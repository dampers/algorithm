int main()
{
	int m,d,k;
	scanf("%d %d",&m,&d);
	if(m == 1 || m == 10) k = d;
	else if(m == 2 || m == 3 || m == 11) d += 3;
	else if(m == 4 || m == 7) d -= 1;
	else if(m == 6) d += 4;
	else if(m == 8) d += 2;
	else if(m == 9 || m == 12) d += 5;
	else if(m == 5) d += 1;
	k = d % 7;
	switch(k)
	{
		case 0:
			printf("SUN");
			break;
		case 1:
			printf("MON");
			break;
		case 2:
			printf("TUE");
			break;
		case 3:
			printf("WED");
			break;
		case 4:
			printf("THU");
			break;
		case 5:
			printf("FRI");
			break;
		case 6:
			printf("SAT");
			break;	
		}	
	return 0;
}
