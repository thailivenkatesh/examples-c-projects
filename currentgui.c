        tempi32Current =BatPack.i32Current[1];
        if(tempi32Current > 0 ){

        	int temp = (tempi32Current);
        	if((tempi32Current>0)&&(tempi32Current<100)){
        		//
        		read_arr[82] = 43; //+.24
        		read_arr[83] = 46;
        		read_arr[84] = temp/10%10+48;
        		read_arr[85] = temp/1%10+48;
        	}
        	else if((tempi32Current>100)&&(tempi32Current<1000)){
        		//int temp= (tempi32Current);
        		read_arr[82] = 43; //+.234
        		read_arr[83] = 46;
        		read_arr[84] = temp/100%10+48;//1
        		read_arr[85] = temp/10%10+48;//2
        		read_arr[86] = temp/1%10+48;//2
        	}
        	else if((tempi32Current>1000)&&(tempi32Current<10000)){
        		//int temp= (tempi32Current);
        		read_arr[82] = 43; //+1.234
        		read_arr[83] = temp/1000%10+48;//1
        		read_arr[84] = 46;
        		read_arr[85] = temp/100%10+48;//1
        		read_arr[86] = temp/10%10+48;//2
        		read_arr[87] = temp/1%10+48;//2
        	}
        	else if(tempi32Current>10000){
        		//int temp= (tempi32Current);
        		read_arr[82] = 43; //+10.234
        		read_arr[83] = temp/10000%10+48;//1
        		read_arr[84] = temp/1000%10+48;//1
        		read_arr[85] = 46;
        		read_arr[86] = temp/100%10+48;//1
        		read_arr[87] = temp/10%10+48;//2
        		read_arr[88] = temp/1%10+48;//2
        	}
        }
        else {//-1029

        	int temp= -(tempi32Current);

        	if((temp>0)&&(temp<100)){
        		//int temp= (tempi32Current);
        		read_arr[82] = 45; //-.23
        		read_arr[83] = 46;
        		read_arr[84] = temp/10%10+48;//1
        		read_arr[85] = temp/1%10+48;//2
        	}
        	else if((temp>100)&&(temp<1000)){
        		//int temp= (tempi32Current);
        		read_arr[82] = 45; //-.234
        		read_arr[83] = 46;
        		read_arr[84] = temp/100%10+48;//1
        		read_arr[85] = temp/10%10+48;//2
        		read_arr[86] = temp/1%10+48;//2
        	}
        	else if((temp>1000)&&(temp<10000)){
        		//int temp= (tempi32Current);
        		read_arr[82] = 45; //-.1.234
        		read_arr[83] = temp/1000%10+48;//1
        		read_arr[84] = 46;
        		read_arr[85] = temp/100%10+48;//1
        		read_arr[86] = temp/10%10+48;//2
        		read_arr[87] = temp/1%10+48;//2
        	}
        	else if(tempi32Current>10000){
        		//int temp= (tempi32Current);
        		read_arr[82] = 45; //-10.234
        		read_arr[83] = temp/10000%10+48;//1
        		read_arr[84] = temp/1000%10+48;//1
        		read_arr[85] = 46;
        		read_arr[86] = temp/100%10+48;//1
        		read_arr[87] = temp/10%10+48;//2
        		read_arr[88] = temp/1%10+48;//2
        	}
        	//Current (A) (*)Standby / (+)Charging / (-)Discharge//*000//81 82 83 84 85
        }
