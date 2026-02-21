void bmsGui_toAscii(){
        uint8_t Power_On_Status=1;
       //Power On Status
        read_arr[66] = Power_On_Status+48;

        uint8_t Guisoc;

        Guisoc=(uint8_t)BatPack.SOC;

        read_arr[68] = Guisoc/100%10+48;
        read_arr[69] = Guisoc/10%10+48;
        read_arr[70] = Guisoc/1%10+48;


       //soh
        read_arr[72] =  BatPack.SOH/100%10+48;
        read_arr[73] =  BatPack.SOH/10%10+48;
        read_arr[74] =  BatPack.SOH/1%10+48;

        //power

       uint16_t icur;
       uint32_t power,temp;


       temp=BatPack.bmsCCCounter/45.6;
       icur = BatPack.bmsStackVoltage*temp;
       power=(uint32_t)icur/1000;

       read_arr[76] = power/10000%10+48;
       read_arr[77] = power/1000%10+48;
       read_arr[78] = power/100%10+48;
       read_arr[79] = power/10%10+48;
       read_arr[80] = power/1%10+48;


   //Current (A) (*)Standby / (+)Charging / (-)Discharge//*000//81 82 83 84 85
   //Charge Cycle  0000//86 87 88 89 90

        //temp min
        uint8_t Temp_Min=BatPack.u16VoltCell[1][15]/100;
        read_arr[92] = Temp_Min/10%10+48;
        read_arr[93] = Temp_Min/1%10+48;
        //temp max
        uint8_t Temp_Max=BatPack.u16VoltCell[1][15]/100;
        read_arr[95] = Temp_Max/10%10+48;
        read_arr[96] = Temp_Max/1%10+48;
        //temp avg;
        uint8_t Temp_Avg=BatPack.u16VoltCell[1][15]/100;
        read_arr[98] = Temp_Avg/10%10+48;
        read_arr[99] = Temp_Avg/1%10+48;

        // uint16_t lowestCellvoltage,highestCellvoltage,highestCellIndex,lowestCell;

        // bmsVoltageSorting(); /*Ascending order*/
        // bmsGetHLVoltageIndexes(&lowestCellvoltage, &highestCellvoltage,&highestCellIndex,&lowestCell);
       //// Volt Min (mV)
        // read_arr[101] = lowestCellvoltage/1000%10+48;
        // read_arr[102] = lowestCellvoltage/100%10+48;
        // read_arr[103] = lowestCellvoltage/10%10+48;
        // read_arr[104] = lowestCellvoltage/1%10+48;
       //// Volt Max (mV)
        // read_arr[106] = highestCellvoltage/1000%10+48;
        // read_arr[107] = highestCellvoltage/100%10+48;
        // read_arr[108] = highestCellvoltage/10%10+48;
        // read_arr[109] = highestCellvoltage/1%10+48;


        //uint16_t Volt_Avg=0;
        //Volt_Avg=(lowestCellvoltage+highestCellvoltage)/2;
        //Volt Avg (mV)
        // read_arr[111] = Volt_Avg/1000%10+48;//cell12
        // read_arr[112] = Volt_Avg/100%10+48;
        // read_arr[113] = Volt_Avg/10%10+48;
        // read_arr[114] = Volt_Avg/1%10+48;


        //Volt Difference
        //uint8_t Volt_Difference;
        //Volt_Difference=highestCellvoltage-lowestCellvoltage;
        // read_arr[116] = 48;//cell12
        // read_arr[117] = 48;
        // read_arr[118] = Volt_Difference/10%10+48;
        // read_arr[119] = Volt_Difference/1%10+48;

       //stack voltage
       read_arr[121] = BatPack.bmsStackVoltage/10000%10+48;
       read_arr[122] = BatPack.bmsStackVoltage/1000%10+48;
       read_arr[123] = BatPack.bmsStackVoltage/100%10+48;
       read_arr[124] = BatPack.bmsStackVoltage/10%10+48;
       read_arr[125] = BatPack.bmsStackVoltage/1%10+48;

      //Min Volt Cutoff (SET VALUE)
       read_arr[127] =  (Batconfig.min_vol_cutoff)/1000%10+48;//
       read_arr[128] =  Batconfig.min_vol_cutoff/100%10+48;
       read_arr[129] =  Batconfig.min_vol_cutoff/10%10+48;
       read_arr[130] =  Batconfig.min_vol_cutoff/1%10+48;

       //Max Volt Cutoff (SET VALUE)
       read_arr[132] = (Batconfig.max_vol_cutoff)/1000%10+48;//
       read_arr[133] = Batconfig.max_vol_cutoff/100%10+48;
       read_arr[134] = Batconfig.max_vol_cutoff/10%10+48;
       read_arr[135] = Batconfig.max_vol_cutoff/1%10+48;

       //Max_Temp_Cut_Off (SET VALUE)//65

       read_arr[137] = Batconfig.max_temp_cutoff/10%10+48;
       read_arr[138] = Batconfig.max_temp_cutoff/1%10+48;

      // Charge_Current_Cut_Off (SET VALUE)//100

       read_arr[140] = Batconfig.chrg_cur_cutoff/100%10+48;
       read_arr[141] = Batconfig.chrg_cur_cutoff/10%10+48;
       read_arr[142] = Batconfig.chrg_cur_cutoff/1%10+48;

      // Discharge_Current_Cut_Off (SET VALUE)//100

       read_arr[144] = Batconfig.dchrg_cur_cutoff /100%10+48;
       read_arr[145] = Batconfig.dchrg_cur_cutoff /10%10+48;
       read_arr[146] = Batconfig.dchrg_cur_cutoff /1%10+48;

       //Temp 1
        read_arr[148] = ((BatPack.u16VoltCell[1][15])/100)/10%10+48;
        read_arr[149] = ((BatPack.u16VoltCell[1][15])/100)/1%10+48;
        //Temp 2
        read_arr[151] = ((BatPack.u16VoltCell[1][16])/100)/10%10+48;
        read_arr[152] = ((BatPack.u16VoltCell[1][16])/100)/1%10+48;
        //Temp 3
        read_arr[154] = ((BatPack.u16VoltCell[1][17])/100)/10%10+48;
        read_arr[155] = ((BatPack.u16VoltCell[1][17])/100)/1%10+48;
        //Temp 4
        read_arr[157] = ((BatPack.u16VoltCell[1][18])/100)/10%10+48;
        read_arr[158] = ((BatPack.u16VoltCell[1][18])/100)/1%10+48;
        //Temp 5
        read_arr[160] = ((BatPack.u16VoltCell[1][19])/100)/10%10+48;
        read_arr[161] = ((BatPack.u16VoltCell[1][19])/100)/1%10+48;
        //Temp 6
        read_arr[163] = ((BatPack.u16VoltCell[1][20])/100)/10%10+48;
        read_arr[164] = ((BatPack.u16VoltCell[1][20])/100)/1%10+48;
        //pcbTemp 7
        read_arr[166] = ((BatPack.u16VoltCell[1][21])/100)/10%10+48;
        read_arr[167] = ((BatPack.u16VoltCell[1][21])/100)/1%10+48;
        //ic Temp 8

        uint8_t tempic=0;
        tempic=BatPack.u16Temp[1]/10;
        read_arr[169] = BatPack.u16Temp[1]/10%10+48;
        read_arr[170] = BatPack.u16Temp[1]/1%10+48;

        read_arr[172] = BatPack.u16VoltCell[1][1]/1000%10+48;//cell1
        read_arr[173] = BatPack.u16VoltCell[1][1]/100%10+48;
        read_arr[174] = BatPack.u16VoltCell[1][1]/10%10+48;
        read_arr[175] = BatPack.u16VoltCell[1][1]/1%10+48;

        read_arr[177] = BatPack.u16VoltCell[1][2]/1000%10+48;//cell2
        read_arr[178] = BatPack.u16VoltCell[1][2]/100%10+48;
        read_arr[179] = BatPack.u16VoltCell[1][2]/10%10+48;
        read_arr[180] = BatPack.u16VoltCell[1][2]/1%10+48;

        read_arr[182] = BatPack.u16VoltCell[1][3]/1000%10+48;//cell3
        read_arr[183] = BatPack.u16VoltCell[1][3]/100%10+48;
        read_arr[184] = BatPack.u16VoltCell[1][3]/10%10+48;
        read_arr[185] = BatPack.u16VoltCell[1][3]/1%10+48;

        read_arr[187] = BatPack.u16VoltCell[1][4]/1000%10+48;//cell4
        read_arr[188] = BatPack.u16VoltCell[1][4]/100%10+48;
        read_arr[189] = BatPack.u16VoltCell[1][4]/10%10+48;
        read_arr[190] = BatPack.u16VoltCell[1][4]/1%10+48;

        read_arr[192] = BatPack.u16VoltCell[1][5]/1000%10+48;//cell5
        read_arr[193] = BatPack.u16VoltCell[1][5]/100%10+48;
        read_arr[194] = BatPack.u16VoltCell[1][5]/10%10+48;
        read_arr[195] = BatPack.u16VoltCell[1][5]/1%10+48;

        read_arr[197] = BatPack.u16VoltCell[1][6]/1000%10+48;//cell6
        read_arr[198] = BatPack.u16VoltCell[1][6]/100%10+48;
        read_arr[199] = BatPack.u16VoltCell[1][6]/10%10+48;
        read_arr[200] = BatPack.u16VoltCell[1][6]/1%10+48;

        read_arr[202] = BatPack.u16VoltCell[1][7]/1000%10+48;//cell7
        read_arr[203] = BatPack.u16VoltCell[1][7]/100%10+48;
        read_arr[204] = BatPack.u16VoltCell[1][7]/10%10+48;
        read_arr[205] = BatPack.u16VoltCell[1][7]/1%10+48;

        read_arr[207] = BatPack.u16VoltCell[1][8]/1000%10+48;//cell8
        read_arr[208] = BatPack.u16VoltCell[1][8]/100%10+48;
        read_arr[209] = BatPack.u16VoltCell[1][8]/10%10+48;
        read_arr[210] = BatPack.u16VoltCell[1][8]/1%10+48;

        read_arr[212] = BatPack.u16VoltCell[1][9]/1000%10+48;//cell9
        read_arr[213] = BatPack.u16VoltCell[1][9]/100%10+48;
        read_arr[214] = BatPack.u16VoltCell[1][9]/10%10+48;
        read_arr[215] = BatPack.u16VoltCell[1][9]/1%10+48;

        read_arr[217] = BatPack.u16VoltCell[1][10]/1000%10+48;//cell10
        read_arr[218] = BatPack.u16VoltCell[1][10]/100%10+48;
        read_arr[219] = BatPack.u16VoltCell[1][10]/10%10+48;
        read_arr[220] = BatPack.u16VoltCell[1][10]/1%10+48;

        read_arr[222] = BatPack.u16VoltCell[1][11]/1000%10+48;//cell11
        read_arr[223] = BatPack.u16VoltCell[1][11]/100%10+48;
        read_arr[224] = BatPack.u16VoltCell[1][11]/10%10+48;
        read_arr[225] = BatPack.u16VoltCell[1][11]/1%10+48;

        read_arr[227] = BatPack.u16VoltCell[1][12]/1000%10+48;//cell12
        read_arr[228] = BatPack.u16VoltCell[1][12]/100%10+48;
        read_arr[229] = BatPack.u16VoltCell[1][12]/10%10+48;
        read_arr[230] = BatPack.u16VoltCell[1][12]/1%10+48;


		 read_arr[232] = BatPack.u16VoltCell[1][13]/1000%10+48;//cell13
        read_arr[233] = BatPack.u16VoltCell[1][13]/100%10+48;
        read_arr[234] = BatPack.u16VoltCell[1][13]/10%10+48;
        read_arr[235] = BatPack.u16VoltCell[1][13]/1%10+48;

        read_arr[237] = BatPack.u16VoltCell[1][14]/1000%10+48;//cell14
        read_arr[238] = BatPack.u16VoltCell[1][14]/100%10+48;
        read_arr[239] = BatPack.u16VoltCell[1][14]/10%10+48;
        read_arr[240] = BatPack.u16VoltCell[1][14]/1%10+48;


		 //SECOND Pack

		 read_arr[242] = BatPack.u16VoltCell[2][1]/1000%10+48;//cell1
        read_arr[243] = BatPack.u16VoltCell[2][1]/100%10+48;
        read_arr[244] = BatPack.u16VoltCell[2][1]/10%10+48;
        read_arr[245] = BatPack.u16VoltCell[2][1]/1%10+48;

        read_arr[247] = BatPack.u16VoltCell[2][2]/1000%10+48;//cell2
        read_arr[248] = BatPack.u16VoltCell[2][2]/100%10+48;
        read_arr[249] = BatPack.u16VoltCell[2][2]/10%10+48;
        read_arr[250] = BatPack.u16VoltCell[2][2]/1%10+48;

        read_arr[252] = BatPack.u16VoltCell[2][3]/1000%10+48;//cell3
        read_arr[253] = BatPack.u16VoltCell[2][3]/100%10+48;
        read_arr[254] = BatPack.u16VoltCell[2][3]/10%10+48;
        read_arr[255] = BatPack.u16VoltCell[2][3]/1%10+48;

        read_arr[257] = BatPack.u16VoltCell[2][4]/1000%10+48;//cell4
        read_arr[258] = BatPack.u16VoltCell[2][4]/100%10+48;
        read_arr[259] = BatPack.u16VoltCell[2][4]/10%10+48;
        read_arr[260] = BatPack.u16VoltCell[2][4]/1%10+48;

        read_arr[262] = BatPack.u16VoltCell[2][5]/1000%10+48;//cell5
        read_arr[263] = BatPack.u16VoltCell[2][5]/100%10+48;
        read_arr[264] = BatPack.u16VoltCell[2][5]/10%10+48;
        read_arr[265] = BatPack.u16VoltCell[2][5]/1%10+48;

        read_arr[267] = BatPack.u16VoltCell[2][6]/1000%10+48;//cell6
        read_arr[268] = BatPack.u16VoltCell[2][6]/100%10+48;
        read_arr[269] = BatPack.u16VoltCell[2][6]/10%10+48;
        read_arr[270] = BatPack.u16VoltCell[2][6]/1%10+48;


        read_arr[272] = BatPack.u16VoltCell[2][7]/1000%10+48;//cell8
        read_arr[273] = BatPack.u16VoltCell[2][7]/100%10+48;
        read_arr[274] = BatPack.u16VoltCell[2][7]/10%10+48;
        read_arr[275] = BatPack.u16VoltCell[2][7]/1%10+48;

        read_arr[277] = BatPack.u16VoltCell[2][8]/1000%10+48;//cell9
        read_arr[278] = BatPack.u16VoltCell[2][8]/100%10+48;
        read_arr[279] = BatPack.u16VoltCell[2][8]/10%10+48;
        read_arr[280] = BatPack.u16VoltCell[2][8]/1%10+48;

        read_arr[282] = BatPack.u16VoltCell[2][9]/1000%10+48;//cell10
        read_arr[283] = BatPack.u16VoltCell[2][9]/100%10+48;
        read_arr[284] = BatPack.u16VoltCell[2][9]/10%10+48;
        read_arr[285] = BatPack.u16VoltCell[2][9]/1%10+48;

        read_arr[287] = BatPack.u16VoltCell[2][10]/1000%10+48;//cell11
        read_arr[288] = BatPack.u16VoltCell[2][10]/100%10+48;
        read_arr[289] = BatPack.u16VoltCell[2][10]/10%10+48;
        read_arr[290] = BatPack.u16VoltCell[2][10]/1%10+48;

        read_arr[292] = BatPack.u16VoltCell[2][11]/1000%10+48;//cell12
        read_arr[293] = BatPack.u16VoltCell[2][11]/100%10+48;
        read_arr[294] = BatPack.u16VoltCell[2][11]/10%10+48;
        read_arr[295] = BatPack.u16VoltCell[2][11]/1%10+48;


		 read_arr[297] = BatPack.u16VoltCell[2][12]/1000%10+48;//cell13
        read_arr[298] = BatPack.u16VoltCell[2][12]/100%10+48;
        read_arr[299] = BatPack.u16VoltCell[2][12]/10%10+48;
        read_arr[300] = BatPack.u16VoltCell[2][12]/1%10+48;

        read_arr[302] = BatPack.u16VoltCell[2][13]/1000%10+48;//cell14
        read_arr[303] = BatPack.u16VoltCell[2][13]/100%10+48;
        read_arr[304] = BatPack.u16VoltCell[2][13]/10%10+48;
        read_arr[305] = BatPack.u16VoltCell[2][13]/1%10+48;

		 read_arr[307] = BatPack.u16VoltCell[2][13]/1000%10+48;//cell14
        read_arr[308] = BatPack.u16VoltCell[2][13]/100%10+48;
        read_arr[309] = BatPack.u16VoltCell[2][13]/10%10+48;
        read_arr[310] = BatPack.u16VoltCell[2][13]/1%10+48;
   }
