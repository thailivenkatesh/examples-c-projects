if(BatPack.i32Current < -180){
		 PRINTF("\n| Charge/Charger CUT Off Enabled \t |\r\n");
         PINS_DRV_ClearPins(DISCHARGE_MOSFET_INSTANCE, 1U << DISCHARGE_MOSFET_PIN);
		 }
if(BatPack.i32Current > 10000)
{
		 PINS_DRV_ClearPins(CHARGE_MOSFET_INSTANCE, 1U << CHARGE_MOSFET_PIN);
		 }