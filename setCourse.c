#include <stdio.h>
#include <stdlib.h>
#include "varset.h"


extern Cs CourseList[8];

void setCourse()
{	
	int cnt;
	for(cnt=0;cnt<8;cnt++)
		CourseList[cnt].total=0;
	
	CourseList[0].cno="k01";
	CourseList[0].cname="c�������";
	CourseList[0].credit=5;
	
	CourseList[1].cno="k02";
	CourseList[1].cname="java����";
	CourseList[1].credit=5;
	
	CourseList[2].cno="k03";
	CourseList[2].cname="java������";
	CourseList[2].credit=4;
	
	CourseList[3].cno="k04";
	CourseList[3].cname="���ݿ����";
	CourseList[3].credit=3;
	
	CourseList[4].cno="k05";
	CourseList[4].cname="Android�ƶ�����";
	CourseList[4].credit=3;
	
	CourseList[5].cno="k06";
	CourseList[5].cname="IOS����";
	CourseList[5].credit=3;
	
	CourseList[6].cno="k07";
	CourseList[6].cname="�����ھ�";
	CourseList[6].credit=4;
	
	CourseList[7].cno="k08";
	CourseList[7].cname="��ҳ���";
	CourseList[7].credit=2;
	
}
