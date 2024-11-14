#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T,len,n,m;
int a[N],b[N];

struct abc{
	int d,n,l;
	bool col;
};

int pos[N*2],id;
bool col[N*2];

abc f[N*2],g[N];
int solve(abc *P,int siz){
	for(int i=0;i<siz;i++) f[i+siz]=f[i]=P[i];
	
	int st=-1;
	for(int i=0;i<siz;i++){
		if(f[i].n!=1){
			st=i;
			break;
		}
	}
	if(st==-1) return 0;
	
	id=0;
	for(int i=st;i<st+siz;i++){
		g[++id]=f[i];
		if(id>1 && g[id].n>1 && g[id-1].n==1){
			int r=id,l=id-1;
			while(g[l].n==1) l--;
			if((r-l)%2==0){
				int d_=0,n_=0;
				for(int t=l;t<r;t++) d_+=g[t].d+g[t].l;
				d_+=g[r].d;
				for(int t=l+1;t<=r;t+=2) d_-=g[t].d;
				
				for(int t=l;t<=r;t+=2) n_+=g[t].n;
				
				id=l-1;
				g[++id]=((abc){d_,n_,g[r].l,g[r].col});
			}
			else{
				for(int t=l+1;t<r;t++){
					g[t].d=g[t].n=2;
					if((t-l)%2) g[t].l=0;
				}
			}
		}
	}
	if(g[id].n==1){
		g[++id]=g[1];
		int r=id,l=id-1;
		while(g[l].n==1) l--;
		if((r-l)%2==0){
			int d_=0,n_=0;
			for(int t=l;t<r;t++) d_+=g[t].d+g[t].l;
			d_+=g[r].d;
			for(int t=l+1;t<=r;t+=2) d_-=g[t].d;
			
			for(int t=l;t<=r;t+=2) n_+=g[t].n;
			
			id=l-1;
			g[++id]=((abc){d_,n_,g[r].l,g[r].col});
		}
		else{
			for(int t=l+1;t<r;t++){
				g[t].d=g[t].n=2;
				if((t-l)%2) g[t].l=0;
			}
		}
		if(l>1){
			for(int i=1;i<id;i++) g[i]=g[i+1];
			id--;
		}
	}
	
	if(id==1) return (g[1].col)?-1:1;
	
	int black_=0,black_2=0,black_1=0,black_pos,white_=0,white_1=0,white_pos;
	for(int i=1;i<=id;i++){
		int lst=(i==1)?(id):(i-1);
		if(g[i].n<3) continue;
		if(g[i].col){
			if(g[i].d>g[i].n) black_++;
			else if(g[lst].l && g[i].l) black_2++;
			else if(g[lst].l || g[i].l) black_1++,black_pos=i;
		}
		else{
			if(g[i].d>g[i].n) white_++;
			else if(g[lst].l || g[i].l) white_1++,white_pos=i;
		}
	}
	if(black_ || black_2 || black_1>=2){
		if(white_ || white_1) return 0;
		else return -1;
	}
	else if(black_1==0){
		if(white_ || white_1) return 1;
		else{
			int s=0;
			for(int i=1;i<=id;i++) s^=g[i].l;
			if(s==0) return -1;
			else return 1;
		}
	}
	else if(black_1==1){
		if(white_ || white_1>=2) return 1;
		int tot=-1;
		abc R[N];
		
		for(int i=1;i<=id;i++) f[i-1]=g[i];
		int pos=black_pos-1,lst=(pos+id-1)%id,nxt=(pos+1)%id;
		if(f[pos].l){
			f[nxt].d+=f[pos].l;
			f[pos].l=0;
		}
		else{
			f[lst].d+=f[lst].l;
			f[lst].l=0;
		}
		for(int i=0;i<id;i++) f[i].col^=1;
		
		if(white_1){
			for(int i=1;i<=id;i++) R[i-1]=g[i];
			pos=white_pos-1,lst=(pos+id-1)%id,nxt=(pos+1)%id;
			if(R[pos].l){
				R[pos].d+=R[pos].l;
				R[pos].l=0;
			}
			else{
				R[pos].d+=R[lst].l;
				R[lst].l=0;
			}
			for(int i=0;i<id;i++) R[i].col^=1;
			int ans1=solve(f,id);
			return max(-ans1,-solve(R,id));
		}
		else return -solve(f,id);
	}
}

int main(){
	cin>>T;
	while(T--){
		cin>>len>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=m;i++) cin>>b[i];
		if(n+m==len){
			puts("C");
			continue;
		}
		
		id=0;
		int p=1,q=1;
		while(p<=n && q<=m){
			if(a[p]<b[q]) pos[++id]=a[p],col[id]=0,p++;
			else pos[++id]=b[q],col[id]=1,q++;
		}
		while(p<=n) pos[++id]=a[p],col[id]=0,p++;
		while(q<=m) pos[++id]=b[q],col[id]=1,q++;
		
		int st=0;
		for(int i=2;i<=id;i++){
			if(col[i]!=col[i-1]){
				st=i;
				break;
			}
		}
		
		int pid=0;
		for(int i=1;i<=id;i++) pos[i+id]=pos[i]+len,col[i+id]=col[i];
		for(int l=st,r;l<st+id;l=r+1){
			r=l;
			while(col[r+1]==col[l]) r++;
			f[pid++]=(abc){pos[r]-pos[l]+1,r-l+1,pos[r+1]-pos[r]-1,col[l]};
		}
		int ans=solve(f,pid);
		if(ans==1) puts("B");
		else if(ans==-1) puts("C");
		else if(ans==0) puts("R");
	}
}

