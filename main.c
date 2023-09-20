#include "reg52.h"
#include "lcd1602.h"
#include "smg.h"
#include "ds18b20.h"
#include "public.h"
#include "string.h"
#include "stdio.h"


// ////////// 土壤湿度传感器-Start //////////
// sbit soil_humidity_sensor = P2^0;

// bit get_soil_humidity_sensor()
// {
//   return soil_humidity_sensor;
// }
// ////////// 土壤湿度传感器-End //////////

// ////////// temperature sensor - start //////////
// // init - start
// u8 temperature_val_i=0;
// int Tempo_val;
// u8 tEmp_bUF[5];
// // init - end

// void temper_RuN() {
// 	temperature_val_i++;
// 	if(temperature_val_i%50==0)
// 		Tempo_val=ds18b20_read_temperture()*10;
// 	if(Tempo_val<0)
// 	{
// 		Tempo_val=-Tempo_val;
// 		tEmp_bUF[0]=0x40;
// 	}
// 	else
// 		tEmp_bUF[0]=0x00;
// 	tEmp_bUF[1]=gsmg_code[Tempo_val/1000];
// 	tEmp_bUF[2]=gsmg_code[Tempo_val%1000/100];
// 	tEmp_bUF[3]=gsmg_code[Tempo_val%1000%100/10]|0x80;
// 	tEmp_bUF[4]=gsmg_code[Tempo_val%1000%100%10];
// 	smg_display(tEmp_bUF,4);
// }
// ////////// temperature sensor - end //////////


////////// independent botton - start //////////
// // init - define botton
// sbit KEY1=P3^1;
// sbit KEY2=P3^0;
// u8 key=0;

// u8 key_scan(u8 mode)
// {
//   static u8 key=1;
//   if(mode)key=1;//连续扫描按键
//   if(key==1&&(KEY1==0||KEY2==0||KEY3==0||KEY4==0))//任意按键按下
//   {
//     delay_10us(1000);//消抖
//     key=0;
//     if(KEY1==0)
//     return KEY1_PRESS;
//     else if(KEY2==0)
//     return KEY2_PRESS;
//     else if(KEY3==0)
//     return KEY3_PRESS;
//     else if(KEY4==0)
//     return KEY4_PRESS;
//   }
//   else if(KEY1==1&&KEY2==1&&KEY3==1&&KEY4==1) //无按键按下
//   {
//     key=1;
//   }
//   return KEY_UNPRESS;
// }

// void key_RuN() {
//   key=key_scan(0);
//   if(key==KEY1_PRESS)//检测按键 K1 是否按下
//   LED1=!LED1;//LED1 状态翻转
// }

////////// independent botton - end //////////



// ////////// lcd1602 - start //////////
// // int to string function - start
// int j;
// char* Int2String(int num,char *str);
 
// char* Int2String(int num,char *str)
// {
//     int i = 0;
//     if(num<0)
//     {
//         num = -num;
//         str[i++] = '-';
//     } 
//     do
//     {
//         str[i++] = num%10+48;
//         num /= 10; 
//     }while(num);
    
//     str[i] = '\0';
    
//     j = 0;
//     if(str[0]=='-')
//     {
//         j = 1;
//         ++i;
//     }
//     for(;j<i/2;j++)
//     {
//         str[j] = str[j] + str[i-1-j];
//         str[i-1-j] = str[j] - str[i-1-j];
//         str[j] = str[j] - str[i-1-j];
//     } 
    
//     return str;
// }
// // int to string function - end

// // default temperature limit value
// int temperature_top_limit = 30;
// int temperature_bottom_limit = 20;

//   char row1[16] = "                ";
//   char row2[16] = "                ";

//   char nul1[16] = "                ";
//   char nul2[16] = "                ";
// // display function - start
// void display() {

//   strcpy(nul2,nul1);
//   strcpy(nul2,row2);
//   strcpy(row2,row1);

//   // display row1
//   strcat(row1, "TTL: ");
//   strcat(row1, Int2String(temperature_top_limit, nul1));
//   strcat(row1, "C");
//   lcd1602_show_string(0,0,row1);
  
//   strcpy(nul2,nul1);
//   // display row2
//   strcat(row2, "TBL: ");
//   strcat(row2, Int2String(temperature_bottom_limit, nul1));
//   strcat(row2, "C");
//   lcd1602_show_string(0,1,row2);
// }





int j;
char* Int2String(int num,char *str);
 
char* Int2String(int num,char *str)
{
    int i = 0;
    if(num<0)
    {
        num = -num;
        str[i++] = '-';
    } 
    do
    {
        str[i++] = num%10+48;
        num /= 10; 
    }while(num);
    
    str[i] = '\0';
    
    j = 0;
    if(str[0]=='-')
    {
        j = 1;
        ++i;
    }
    for(;j<i/2;j++)
    {
        str[j] = str[j] + str[i-1-j];
        str[i-1-j] = str[j] - str[i-1-j];
        str[j] = str[j] - str[i-1-j];
    } 
    
    return str;
}

char numberTable[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}; // ��ʾ�����ַ�����
	char str1[16] = {'M', 'r', '.', ' ', 'W', 'a', 'n', 'g'};
	char result[16] = {'H', 'e', 'l', 'l', 'o', ' '};
	char str2[16] = "go to vault ";
	char res2[16] = {0x31, 0x30, 0x31};
char num_to_str(int num)
{
	char str[10];
	sprintf(str, "%d", num);
	return str;
}


////////// lcd1602 - end //////////
void main()
{	
	// ds18b20_init();
  // lcd1602_init();
	// while(1)
	// {		
  //   temper_RuN();	
  //   lcd1602_clear();
  //   display();
	// }		
	u8 i=0;
   	int temp_value;
	u8 temp_buf[5];

	ds18b20_init();//��ʼ��DS18B20




	lcd1602_init();
	while(1)
	{				
		i++;
		if(i%50==0)//���һ��ʱ���ȡ�¶�ֵ�����ʱ��Ҫ�����¶ȴ�����ת���¶�ʱ��
			temp_value=ds18b20_read_temperture()*10;//�����¶�ֵС����һλ
		if(temp_value<0)//���¶�
		{
			temp_value=-temp_value;
			temp_buf[0]=0x40;//��ʾ����	
		}
		else
			temp_buf[0]=0x00;//����ʾ
		temp_buf[1]=gsmg_code[temp_value/1000];//��λ
		temp_buf[2]=gsmg_code[temp_value%1000/100];//ʮλ
		temp_buf[3]=gsmg_code[temp_value%1000%100/10]|0x80;//��λ+С����
		temp_buf[4]=gsmg_code[temp_value%1000%100%10];//С�����һλ
		smg_display(temp_buf,4);




    
	delay_ms(5000);
	lcd1602_clear();
	lcd1602_show_string(0,0,"Good morning!");
	lcd1602_show_string(0,1,"Vault-Tech");
	
	delay_ms(5000);
	lcd1602_clear();
	strcat(result, str1);
	strcat(str2, Int2String(101, res2));
	lcd1602_show_string(0,0, result);
	lcd1602_show_string(0,1, str2);
	}		
}