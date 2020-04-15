#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin>>tc;
	vector<int> red, green, blue;
	while(tc--)
	{
		int nr, ng, nb;
		cin>>nr>>ng>>nb;
		red.resize(nr);
		green.resize(ng);
		blue.resize(nb);
		int ntmp = 0;
		for(int i=0;i<nr;i++)
			cin>>red[i];
		for(int i=0;i<ng;i++)
			cin>>green[i];
		for(int i=0;i<nb;i++)
			cin>>blue[i];
		sort(red.begin(), red.end());
		sort(green.begin(), green.end());
		sort(blue.begin(), blue.end());
		vector<int>::iterator lowg, upg, llowg;
		lld mn = LLONG_MAX, tmp = 0LL;
		for(int i=0;i<nr;i++)
		{
			int reds = red[i];
			lowg = lower_bound(green.begin(), green.end(), reds);
			upg = upper_bound(green.begin(), green.end(), reds);
			if(lowg==upg) upg++;

			if(lowg-green.begin()==ng) lowg--;
			else if(lowg-green.begin()<0) lowg++;
			if(upg-green.begin()==ng) upg--;
			else if(upg-green.begin()<0) upg++;

			llowg = lowg-1;
			if(llowg-green.begin()<0) llowg++;
			else if(llowg-green.begin()==ng) llowg--;

			int gr = green[lowg-green.begin()];
			int ugr = green[upg-green.begin()];
			int llgr = green[llowg-green.begin()];

			vector<int>::iterator lrtb, urtb, lowlrtb, lgtb, ugtb, lowlgtb;
			vector<int>::iterator lgrb, ugrb, lowlgrb, lowgrb, lowugrb, lowlowgrb;
			lrtb = lower_bound(blue.begin(), blue.end(), reds);
			urtb = upper_bound(blue.begin(), blue.end(), reds);
			if(lrtb==urtb) urtb++;

			lgtb = lower_bound(blue.begin(), blue.end(), gr);
			ugtb = upper_bound(blue.begin(), blue.end(), gr);
			if(lgtb==ugtb) ugtb++;
			
			lgrb = lower_bound(blue.begin(), blue.end(), ugr);
			ugrb = upper_bound(blue.begin(), blue.end(), ugr);
			if(lgrb==ugrb) ugrb++;
			
			lowgrb = lower_bound(blue.begin(), blue.end(), llgr);
			lowugrb = upper_bound(blue.begin(), blue.end(), llgr);
			if(lowgrb==lowugrb) lowugrb++;

			if(lrtb-blue.begin()==nb) lrtb--;
			else if(lrtb-blue.begin()<0) lrtb++;
			if(urtb-blue.begin()==nb) urtb--;
			else if(urtb-blue.begin()<0) urtb++;
			if(lgtb-blue.begin()==nb) lgtb--;
			else if(lgtb-blue.begin()<0) lgtb++;
			if(ugtb-blue.begin()==nb) ugtb--;
			else if(ugtb-blue.begin()<0) ugtb++;
			if(lgrb-blue.begin()==nb) lgrb--;
			else if(lgrb-blue.begin()<0) lgrb++;
			if(ugrb-blue.begin()==nb) ugrb--;
			else if(ugrb-blue.begin()<0) ugrb++;
			if(lowgrb-blue.begin()==nb) lowgrb--;
			else if(lowgrb-blue.begin()<0) lowgrb++;
			if(lowugrb-blue.begin()==nb) lowugrb--;
			else if(lowugrb-blue.begin()<0) lowugrb++;


			lowlrtb = lrtb-1;
			lowlgtb = lgtb-1;
			lowlgrb = lgrb-1;
			lowlowgrb = lowgrb-1;
			if(lowlrtb-blue.begin()<0) lowlrtb++;
			else if(lowlrtb-blue.begin()==nb) lowlrtb--;
			if(lowlgtb-blue.begin()<0) lowlgtb++;
			else if(lowlgtb-blue.begin()==nb) lowlgtb--;
			if(lowlgrb-blue.begin()<0) lowlgrb++;
			else if(lowlgrb-blue.begin()==nb) lowlgrb--;
			if(lowlowgrb-blue.begin()<0) lowlowgrb++;
			else if(lowlowgrb-blue.begin()==nb) lowlowgrb--;

			int llrtb = blue[lrtb-blue.begin()];
			int uurtb = blue[urtb-blue.begin()];
			int llowlrtb = blue[lowlrtb-blue.begin()];

			int llgtb = blue[lgtb-blue.begin()];
			int uugtb = blue[ugtb-blue.begin()];
			int llowlgtb = blue[lowlgtb-blue.begin()];

			int llgrb = blue[lgrb-blue.begin()];
			int uugrb = blue[ugrb-blue.begin()];
			int llowlgrb = blue[lowlgrb-blue.begin()];

			int llowgrb = blue[lowgrb-blue.begin()];
			int llowugrb = blue[lowugrb-blue.begin()];
			int llowlowgrb = blue[lowlowgrb-blue.begin()];

			lld ktmp = 0LL;
			tmp = (lld)(reds-llrtb)*(reds-llrtb);
			ktmp = (lld)(reds-gr)*(reds-gr);
			ktmp += (lld)(gr-llrtb)*(gr-llrtb);
			mn = min(tmp+ktmp, mn);

			ktmp = (lld)(reds-ugr)*(reds-ugr);
			ktmp += (lld)(ugr-llrtb)*(ugr-llrtb);
			mn = min(tmp+ktmp, mn);

			ktmp = (lld)(reds-llgr)*(reds-llgr);
			ktmp += (lld)(llgr-llrtb)*(llgr-llrtb);
			mn = min(tmp+ktmp, mn);


			tmp = (lld)(reds-uurtb)*(reds-uurtb);
			ktmp = (lld)(reds-gr)*(reds-gr);
			ktmp += (lld)(gr-uurtb)*(gr-uurtb);
			mn = min(tmp+ktmp, mn);

			ktmp = (lld)(reds-ugr)*(reds-ugr);
			ktmp += (lld)(ugr-uurtb)*(ugr-uurtb);
			mn = min(tmp+ktmp, mn);

			ktmp = (lld)(reds-llgr)*(reds-llgr);
			ktmp += (lld)(llgr-uurtb)*(llgr-uurtb);
			mn = min(tmp+ktmp, mn);


			tmp = (lld)(reds-llowlrtb)*(reds-llowlrtb);
			ktmp = (lld)(reds-gr)*(reds-gr);
			ktmp += (lld)(gr-llowlrtb)*(gr-llowlrtb);
			mn = min(tmp+ktmp, mn);


			ktmp = (lld)(reds-ugr)*(reds-ugr);
			ktmp += (lld)(ugr-llowlrtb)*(ugr-llowlrtb);
			mn = min(tmp+ktmp, mn);


			ktmp = (lld)(reds-llgr)*(reds-llgr);
			ktmp += (lld)(llgr-llowlrtb)*(llgr-llowlrtb);
			mn = min(tmp+ktmp, mn);


			tmp = (lld)(reds-gr)*(reds-gr);
			ktmp = (lld)(reds-llgtb)*(reds-llgtb);
			ktmp += (lld)(gr-llgtb)*(gr-llgtb);
			mn = min(tmp+ktmp, mn);

			ktmp = (lld)(reds-uugtb)*(reds-uugtb);
			ktmp += (lld)(gr-uugtb)*(gr-uugtb);
			mn = min(tmp+ktmp, mn);

			ktmp = (lld)(reds-llowlgtb)*(reds-llowlgtb);
			ktmp += (lld)(gr-llowlgtb)*(gr-llowlgtb);
			mn = min(tmp+ktmp, mn);


			tmp = (lld)(reds-ugr)*(reds-ugr);
			ktmp = (lld)(reds-llgrb)*(reds-llgrb);
			ktmp += (lld)(ugr-llgrb)*(ugr-llgrb);
			mn = min(tmp+ktmp, mn);

			ktmp = (lld)(reds-uugrb)*(reds-uugrb);
			ktmp += (lld)(ugr-uugrb)*(ugr-uugrb);
			mn = min(tmp+ktmp, mn);

			ktmp = (lld)(reds-llowlgrb)*(reds-llowlgrb);
			ktmp += (lld)(ugr-llowlgrb)*(ugr-llowlgrb);
			mn = min(tmp+ktmp, mn);
			

			tmp = (lld)(reds-llgr)*(reds-llgr);
			ktmp = (lld)(reds-llowgrb)*(reds-llowgrb);
			ktmp += (lld)(llgr-llowgrb)*(llgr-llowgrb);
			mn = min(tmp+ktmp, mn);

			ktmp = (lld)(reds-llowugrb)*(reds-llowugrb);
			ktmp += (lld)(llgr-llowugrb)*(llgr-llowugrb);
			mn = min(tmp+ktmp, mn);

			ktmp = (lld)(reds-llowlowgrb)*(reds-llowlowgrb);
			ktmp += (lld)(llgr-llowlowgrb)*(llgr-llowlowgrb);
			mn = min(tmp+ktmp, mn);

		}
		cout<<mn<<endl;
	}
	return 0;
}