#include <bits/stdc++.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


using namespace std;

int val[500001];
int cnt[8001];



int main() {
	int num, avg, sum=0, mid, most, min, max;
	scanf("%d", &num);
	
	for(int i=0; i<num; i++){
		scanf(" %d", &val[i]);
		cnt[val[i]+4000]++;
	}
	
	//�ֺ��� ���ϴ°Ŵ�~
	int cmax = 0, tmax = 0; 
	for(int i = 8000; i>=0; i--)
		{
			if(cnt[cmax] < cnt[i]){
				cmax = i;
				tmax = i;
			}
			
			else if(cnt[cmax] == cnt[i]){
				cmax = tmax;
				tmax = i;
			}
		}
	
	//������ �߾Ӱ� ���ϱ� 
	sort(val, val+num);
	mid = val[(num-1)/2]; 
	
	//��� ���ϱ� 
	for(int i=0; i<num; i++)
	{
		sum += val[i];
	}
	avg = round(1.0*sum/num);
	
	min = val[0]; max = val[num-1];
	
	printf("%d\n", avg);
	printf("%d\n", mid);
	printf("%d\n", cmax-4000);
	printf("%d\n", (max-min));
	
		

	
	//system("pause");
	return 0;
}
