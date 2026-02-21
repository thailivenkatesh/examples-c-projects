 #include <stdio.h>
	getBatpackSOC(float Stackvoltage1){
	if(Stackvoltage <= 34480) {
 		return 0;
 	} else if(Stackvoltage > 34480 && Stackvoltage <= 34498.08) {
 		return 1;
 	} else if(Stackvoltage > 34498.08 && Stackvoltage <= 35704.68) {
 		return 2;
 	} else if(Stackvoltage > 35704.68 && Stackvoltage <= 36533.4) {
 		return 3;
 	} else if(Stackvoltage > 36533.4 && Stackvoltage <= 37169.76) {
 		return 4;
	}else if(Stackvoltage > 37169.76 && Stackvoltage <= 37682.52) {
 		return 5;
 	} else if(Stackvoltage > 37682.52 && Stackvoltage <= 38109) {
 		return 6;
 	} else if(Stackvoltage > 38109 && Stackvoltage <= 38451.48) {
 		return 7;
 	} else if(Stackvoltage > 38451.48 && Stackvoltage <= 38630) {
 		return 8;
 	} else if(Stackvoltage > 38630 && Stackvoltage <= 38659) {
 		return 9;
 	} else if(Stackvoltage > 38659 && Stackvoltage <= 38679) {
 		return 10;
 	} else if(Stackvoltage > 38679 && Stackvoltage <= 38727) {
 		return 11;
 	} else if(Stackvoltage > 38727 && Stackvoltage <= 38775) {
 		return 12;
 	} else if(Stackvoltage > 38775 && Stackvoltage <= 38811) {
 		return 13;
 	} else if(Stackvoltage > 38811 && Stackvoltage <= 38847) {
 		return 14;
 	} else if(Stackvoltage > 38847 && Stackvoltage <= 38897) {
 		return 15;
 	} else if(Stackvoltage > 38897 && Stackvoltage <= 38976) {
 		return 16;
 	} else if(Stackvoltage > 38976 && Stackvoltage <= 39048) {
 		return 17;
 	}else if(Stackvoltage > 39048 && Stackvoltage <= 39120) {
 		return 18;
 	} else if(Stackvoltage > 39120 && Stackvoltage <= 39180) {
 		return 19;
 	} else if(Stackvoltage > 39180 && Stackvoltage <= 39249) {
 		return 20;
 	} else if(Stackvoltage > 39249 && Stackvoltage <= 39288) {
 		return 21;
 	} else if(Stackvoltage > 39288 && Stackvoltage <= 39336) {
 		return 22;
 	} else if(Stackvoltage > 39336 && Stackvoltage <= 39384) {
 		return 23;
 	} else if(Stackvoltage > 39384 && Stackvoltage <= 39444) {
 		return 24;
 	} else if(Stackvoltage > 39444 && Stackvoltage <= 39507) {
 		return 25;
 	} else if(Stackvoltage > 39507 && Stackvoltage <= 39528) {
 		return 26;
 	} else if(Stackvoltage > 39528 && Stackvoltage <= 39552) {
 		return 27;
 	} else if(Stackvoltage > 39552 && Stackvoltage <= 39576) {
 		return 28;
 	} else if(Stackvoltage > 39576 && Stackvoltage <= 39600) {
 		return 29;
 	} else if(Stackvoltage > 39600 && Stackvoltage <= 39651) {
 		return 30;
 	} else if(Stackvoltage > 39651 && Stackvoltage <= 39660) {
 		return 31;
 	} else if(Stackvoltage > 39660 && Stackvoltage <= 39663) {
 		return 32;
 	} else if(Stackvoltage > 39663 && Stackvoltage <= 39672) {
 		return 33;
 	} else if(Stackvoltage > 39672 && Stackvoltage <= 39675) {
 		return 34;
 	}else if(Stackvoltage > 39675 && Stackvoltage <= 39684) {
 		return 35;
 	} else if(Stackvoltage > 39684 && Stackvoltage <= 39687) {
 		return 36;
 	} else if(Stackvoltage > 39687 && Stackvoltage <= 39691) {
 		return 37;
 	} else if(Stackvoltage > 39691 && Stackvoltage <= 39694) {
 		return 38;
 	} else if(Stackvoltage > 39694 && Stackvoltage <= 39696) {
 		return 39;
 	} else if(Stackvoltage > 39696 && Stackvoltage <= 39697) {
 		return 40;
 	} else if(Stackvoltage > 39697 && Stackvoltage <= 39699) {
 		return 41;
 	} else if(Stackvoltage > 39699 && Stackvoltage <= 39700) {
 		return 42;
 	} else if(Stackvoltage > 39700 && Stackvoltage <= 39703) {
 		return 43;
 	} else if(Stackvoltage > 39703 && Stackvoltage <= 39704) {
 		return 44;
 	} else if(Stackvoltage > 39704 && Stackvoltage <= 39706) {
 		return 45;
 	} else if(Stackvoltage > 39706 && Stackvoltage <= 39712) {
 		return 46;
 	} else if(Stackvoltage > 39712 && Stackvoltage <= 39718) {
 		return 47;
 	} else if(Stackvoltage > 39718 && Stackvoltage <= 39722) {
 		return 48;
 	} else if(Stackvoltage > 39722 && Stackvoltage <= 39726) {
 		return 49;
 	} else if(Stackvoltage > 39726 && Stackvoltage <= 39731) {
 		return 50;
 	} else if(Stackvoltage > 39731 && Stackvoltage <= 39734) {
 		return 51;
 	}else if(Stackvoltage > 39734 && Stackvoltage <= 39738) {
 		return 52;
 	} else if(Stackvoltage > 39738 && Stackvoltage <= 39741) {
 		return 53;
 	} else if(Stackvoltage > 39741 && Stackvoltage <= 39745) {
 		return 54;
 	} else if(Stackvoltage > 39745 && Stackvoltage <= 39748) {
 		return 55;
 	} else if(Stackvoltage > 39748 && Stackvoltage <= 38754) {
 		return 56;
 	} else if(Stackvoltage > 38754 && Stackvoltage <= 39763) {
 		return 57;
 	} else if(Stackvoltage > 39763 && Stackvoltage <= 39771) {
 		return 58;
 	} else if(Stackvoltage > 39771 && Stackvoltage <= 39780) {
 		return 59;
 	} else if(Stackvoltage > 39780 && Stackvoltage <= 39788) {
 		return 60;
 	} else if(Stackvoltage > 39788 && Stackvoltage <= 39816) {
 		return 61;
 	} else if(Stackvoltage > 39816 && Stackvoltage <= 39852) {
 		return 62;
 	} else if(Stackvoltage > 39852 && Stackvoltage <= 39888) {
 		return 63;
 	} else if(Stackvoltage > 39888 && Stackvoltage <= 39936) {
 		return 64;
 	} else if(Stackvoltage > 39936 && Stackvoltage <= 39985) {
 		return 65;
 	} else if(Stackvoltage > 39985 && Stackvoltage <= 39996) {
 		return 66;
 	} else if(Stackvoltage > 39996 && Stackvoltage <= 40032) {
 		return 67;
 	} else if(Stackvoltage > 40032 && Stackvoltage <= 40056) {
 		return 68;
 	}else if(Stackvoltage > 40056 && Stackvoltage <= 40080) {
 		return 69;
 	} else if(Stackvoltage > 40080 && Stackvoltage <= 40124) {
 		return 70;
 	} else if(Stackvoltage == 40115) {
 		return 71;
 	} else if(Stackvoltage == 40115.1) {
 		return 72;
 	} else if(Stackvoltage ==40115.2) {
 		return 73;
 	} else if(Stackvoltage == 40115.3) {
 		return 74;
 	} else if(Stackvoltage == 40115.4) {
 		return 75;
 	} else if(Stackvoltage == 40115.5) {
 		return 76;
 	} else if(Stackvoltage == 40115.6) {
 		return 77;
 	} else if(Stackvoltage = 40115.7) {
 		return 78;
 	} else if(Stackvoltage == 40115.64) {
 		return 79;
 	} else if(Stackvoltage == 40117.8) {
 		return 80;
 	} else if(Stackvoltage == 40117.6) {
 		return 81;
 	} else if(Stackvoltage == 40117.4) {
 		return 82;
 	} else if(Stackvoltage == 40117.2) {
 		return 83;
 	} else if(Stackvoltage == 40117) {
 		return 84;
 	} else if(Stackvoltage < 40117 && Stackvoltage >= 40116.5) {
 		return 85;
 	}else if(Stackvoltage < 40116.5 && Stackvoltage >= 40108.9) {
 		return 86;
 	} else if(Stackvoltage == 40108.92) {
 		return 87;
 	} else if(Stackvoltage == 40108.93) {
 		return 88;
 	} else if(Stackvoltage == 40108.95) {
 		return 89;
 	} else if(Stackvoltage == 40108.97) {
 		return 90;
 	} else if(Stackvoltage == 40084.68) {
 		return 91;
 	} else if(Stackvoltage == 40084.67) {
 		return 92;
 	} else if(Stackvoltage == 40084.66) {
 		return 93;
 	} else if(Stackvoltage == 40084.65) {
 		return 94;
 	} else if(Stackvoltage == 40084.64) {
 		return 95;
 	} else if(Stackvoltage > 40084.64 && Stackvoltage <= 40086) {
 		return 96;
 	} else if(Stackvoltage > 40086 && Stackvoltage <= 40088) {
 		return 97;
 	} else if(Stackvoltage > 40088 && Stackvoltage <= 40092) {
 		return 98;
 	} else if(Stackvoltage > 40092 && Stackvoltage <= 40140) {
 		return 99;
 	} else if(Stackvoltage > 40140 && Stackvoltage <= 40778) {
	return 100;}
 }
 
 
 int main()
{
	float Stackvoltage,Stackvoltage1;
	Stackvoltage1=38400;
	Stackvoltage=getBatpackSOC(Stackvoltage1);

}