template<class Type>
Type MaxLoading(Type w[],Type c,int n,int bestx[])
{
	//initiating
	//活结点队列
	Queue<QNode<Type>*> Q,Que;
	//同层结点尾部标志
	Q.Add(0);
	//当前扩展结点所处的层
	int i=1;
	Type Ew=0,bestw=0,r=0;
	for (int j=2;j<=n;j++)
		r+=w[i];
	QNode<Type> *E=0,*bestE;
	while (true)
	{
		Type wt=Ew+w[i];
		bool del=true;
		if(wt<=c){
			if(wt>bestw)
				bestw=wt;
			EnQueue(Q,wt,i,n,bestw,E,bestE,bestx,true);
			del=false;
		}
		if(Ew+r>bestw){
			EnQueue(Q,wt,i,n,bestw,E,bestE,bestx,false);
			del=false;
		}
		if(E){
			if(del)
				delete E;
			else
				Que.Add(E);
		}
		Q.Delete(E);

		if(!E){
			if (Q.IsEmpty())
				break;
			Q.Add(0);
			Q.Delete(E);
			i++;
			r-=w[i];
		}
		Ew=e->weight;
	}

	for (j=n-1;j>0;j--){
		bestx[j]=bestE->LChild;
		bestE=bestE->parent;
	}

	while(!Que.IsEmpty()){
		QNode<Type> *b;
		Que.Delete(b);
		delete b;
	}
	return bestw;
}
