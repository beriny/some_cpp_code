/************************************************************************
 *	>    File Name: stof.c
 *	>       Author: huangjinqiang
 *	>        Email: ligelaige@gmail.com
 *	> Created Time: 2014年05月10日 星期六 11时09分08秒
 ************************************************************************/

/**
 * float stof(char* str)
 * 特性：将字符串str 转成float，能够忽略除0-9、‘.’和‘-’以外的字符
 * 缺点：精度不高
 * double stolf(char* str)
 * 除了拥有stof的特性之外，克服了精度不高的缺点
 */

float stof(char* str)
{
	float resulta = 0;//整数部分
	float resultb = 0;//小数部分分子
	float resultc = 1;//小数分母分子
	
	int a = 1;//小数点标识位
	int b = 1;//负号标识位
	
	int i = 0;	
	while(str[i]!='\0')
	{
		if (str[i] == '-')
		{
			b = -1;
		}
		if (a == 1) {			
			if (str[i] >= '0' && str[i] <= '9') {
				resulta *= 10;
				resulta += (float)(str[i]-'0');
			} else if ( str[i] == '.') {
				a = 0;				
			}
		} else {
			if (str[i] >= '0' && str[i] <= '9') {
				resultc *= 10;
				resultb *= 10;
				resultb += (float)(str[i]-'0');
			}		
		}
		i++;
	}
	return (resulta + resultb / resultc) * b;
}

double stolf(char* str)
{
	double resulta = 0;
	double resultb = 0;
	double resultc = 1;
	
	int a = 1;//小数点标识位
	int b = 1;//负号标识位
		
	int i = 0;	
	while(str[i]!='\0')
	{
		if (str[i] == '-')
		{
			b = -1;
		}
		if (a == 1) {			
			if (str[i] >= '0' && str[i] <= '9') {
				resulta *= 10;
				resulta += (double)(str[i]-'0');
			} else if ( str[i] == '.') {
				a = 0;				
			}
		} else {
			if (str[i] >= '0' && str[i] <= '9') {
				resultc *= 10;
				resultb *= 10;
				resultb += (double)(str[i]-'0');
			}		
		}
		i++;
	}
	return (resulta + resultb / resultc) * b;
}
