#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define MAXBYTES 84
char u8PktBuf[MAXBYTES];

// --- DATA STRUCTURE ---
typedef struct {
    int lpcount;
    int cells[14];
    long s32mA;
    int Temp;
} BMSData_t;

// --- HELPER: FILL (SENDER) ---
void fill_field(int start_idx, int len, long value) {
    long temp = (value < 0) ? -value : value;
    for (int i = len - 1; i >= 0; i--) {
        u8PktBuf[start_idx + i] = (char)((temp % 10) + '0');
        temp /= 10;
    }
    if (value < 0) u8PktBuf[start_idx] = '-';
}

// --- HELPER: EXTRACT (RECEIVER) ---
long extract_field(const char *buf, int start_idx, int len) {
    long result = 0;
    int is_neg = (buf[start_idx] == '-');
    int i = (is_neg) ? 1 : 0;

    for (; i < len; i++) {
        if (buf[start_idx + i] >= '0' && buf[start_idx + i] <= '9') {
            result = result * 10 + (buf[start_idx + i] - '0');
        }
    }
    return is_neg ? -result : result;
}

// --- MAIN FUNCTIONS ---
void FormPacketSA(BMSData_t *data) {
    memset(u8PktBuf, '0', 79); // Fill with '0' as default padding
    u8PktBuf[0] = '#'; u8PktBuf[1] = 'S'; u8PktBuf[2] = 'A';

    fill_field(3, 8, data->lpcount);
    for (int i = 0; i < 14; i++) {
        fill_field(11 + (i * 4), 4, data->cells[i]);
    }
    fill_field(67, 8, data->s32mA);
    fill_field(75, 4, data->Temp);
}

void ParsePacketSA(const char *buf, BMSData_t *out) {
    if (buf[0] != '#' || buf[1] != 'S' || buf[2] != 'A') return;

    out->lpcount = (int)extract_field(buf, 3, 8);
    for (int i = 0; i < 14; i++) {
        out->cells[i] = (int)extract_field(buf, 11 + (i * 4), 4);
    }
    out->s32mA = extract_field(buf, 67, 8);
    out->Temp = (int)extract_field(buf, 75, 4);
}

int main() {
    // 1. Setup Sample Data
    BMSData_t tx_data = {
        .lpcount = 202,
        .cells = {3001, 3002, 3003, 3004, 3005, 3006, 3007, 3008, 3009, 3010, 3011, 3012, 3013, 3014},
        .s32mA = -337,
        .Temp = 25
    };
    BMSData_t rx_data;

    // 2. FORM PACKET (Sender Side)
    FormPacketSA(&tx_data);
    printf("Raw Packet: %.79s\n\n", u8PktBuf);

    // 3. EXTRACT DATA (Receiver Side)
    ParsePacketSA(u8PktBuf, &rx_data);

    // 4. VERIFY
    printf("--- Extracted Results ---\n");
    printf("Loop Count: %d\n", rx_data.lpcount);
    printf("Cell 1: %d mV | Cell 14: %d mV\n", rx_data.cells[0], rx_data.cells[12]);
    printf("Current: %ld mA\n", rx_data.s32mA);
    printf("Temp: %d C\n", rx_data.Temp);

    return 0;
}
