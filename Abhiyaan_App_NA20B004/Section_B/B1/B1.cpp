#include <iostream>

using namespace std;

struct ZeroAndOne
{
	int pos, size;	
};

int main()
{
	int n, i, s, e, sc = 0, ec = 0;
	cout << "Enter array size\n"; cin >> n;
	int a[n]; s = 0; e = n-1;
	cout << "\nEnter array values (each entry must either be a 1 or a 0)\n";
	for(i=0; i<n; i++)
	{
		cin >> a[i];
	}
	for(i=0; i<n; i++)
	{
		if(sc==0 && a[i]==0)
			s++;
		else 
			sc++;
		if(ec==0 && a[n-i-1]==0)
			e--;
		else
			ec++;
	}
	//cout << "\n" << s+1 << " " << e+1;
	int m = e-s+1, k = 0, j=0;
	int b[m];
	struct ZeroAndOne z[m], o[m];
	for(i=0; i<m; i++)
		b[i] = a[i+s];
	for(i=0; i<m; i++)
	{
		
		//cout << b[i] << " ";
		if(b[i]==0 && b[i-1]==1)
		{
			z[j].pos = i;
			j++;
		}	
		if((b[i]==1 && b[i-1]==0) || i==0)
		{
			o[k].pos = i;
			k++;
		}		
	}
	for(i=0; i<j; i++)
	{
		z[i].size = o[i+1].pos - z[i].pos;
	}
	for(i=0; i<k; i++)
	{
		if(i<k-1)
			o[i].size = o[i+1].pos - o[i].pos - z[i].size;
		else
			o[i].size = m - o[i].pos;
	}
	
	
	int min_min = 0, min[k], l, g;

	for(i=0; i<k; i++)
	{
		min[i] = 0;
		for(l=0; l<k; l++)
		{
			if(l>i)
			{
				for(g=i; g<l; g++)
				{
					min[i] = min[i] + (z[g].size)*(o[l].size);	
				}
			}
			else if(i>l)
			{
				for(g=l; g<i; g++)
				{
					min[i] = min[i] + (z[g].size)*(o[l].size);
				}
			}
		}
		//cout << min[i] << " ";
	}
	min_min = min[0];
	
	for(i=0; i<k; i++)
	{
		if(min[i] < min_min)
			min_min = min[i];
	}
	cout << "\n" << "Minimum number of switches to group all the 1s together is = " << min_min << endl;
	return 0;
}
