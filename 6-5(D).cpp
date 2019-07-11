//修改后的0-1背包问题的优先队列式分支限界法
template<class Typew,class Typep>
Typep Knap<Typew,Typep>::MaxKnapsack()
{
	H=new MaxHeap<HeapNode<Typep,Typew>>(1000);
	Queue<bbnode *> Que;
	bestx=new int[n+1];
	int i=1;
	E=0;
	cw=cp=0;
	Typep bestp=0;
	Typep up=Bound(1);

	//搜索子集空间树
	while(i!=n+1){
		Typew wt=cw+w[i];
		if(wt<=c){
			if(cp+p[i]>bestp)
				bestp=cp+p[i];
			AddLiveNode(up,cp+p[i],cw+w[i],true,i+1);
			up=Bound(i+1);
			//检查当前扩展结点的右儿子结点
			if(up>=bestp)
				AddLiveNode(up,cp,cw,false,i+1);
			HeapNode<Typep,Typew> N;
			H->DeleteMax(N);
			E=N.ptr;
			Que.Add(E);
			cw=N.weight;
			cp=N.profit;
			up=N.uprofit;
			i=N.level;
		}

		for(int j=n;j>0;j--){
			bestx[j]=E->LChild;
			E=E->parent;
		}

		HeapNode<Typep,Typew> N;
		while(true){
			try{ 
				H->DeleteMax(N);
			}
			catch(OutOfBounds){
				break;
			}
			Que.Add(N.ptr);
		}
		while(!Que.IsEmpty()){
			bbnode* b;
			Que.Delete(b);
			delete b;
		}
	}
	return cp;
}



//修改后的解装载问题的优先队列式分支限界法
template<class Type>
Type MaxLoading(Type *w,Type c,int n,int *bestx)
{
	MaxHeap<HeapNode<Type>> H(1000);
	Queue<bbnode *> Quel
	T *r=new Y[n+1];
	r[n]=0;
	for (int j=n-1,j>0;j--)
		r[j]=r[j+1]+w[j+1];
	int i=1;
	bbnode *E=0;
	int Ew=0;
	while(i!=n+1){
		if(Ew+w[i]<=c)
			AddLiveNode(H,E,Ew+w[i]+r[i],true,i+1);
		AddLiveNode(H,E,Ew+r[i],false,i+1);
		HeapNode<Type> N;
		H.DeleteMax(N);
		i=N.level;
		E.N.ptr;
		Que.Add(E);
		Ew=N.uweight-r[i-1];
	}

	for(j=n;j>0;j-){
		bestx[j]=e->LChild;
		E=E->parent;
	}

	HeapNode<Typep,Typew> N;
	while(true){
		try{ 
			H->DeleteMax(N);
		}
		catch(OutOfBounds){
			break;
		}
		Que.Add(N.ptr);
	}
	while(!Que.IsEmpty()){
		bbnode* b;
		Que.Delete(b);
		delete b;
	}
	return Ew;
}