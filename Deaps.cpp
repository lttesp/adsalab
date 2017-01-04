#include<iostream>
#include<conio.h>
#include<math.h>
class Deap
{
	public:
		int maxsize;
		int size;
	public:
		int *h;
	public:
		Deap(int,int);
		int leftchild(int);
		int rightchild(int);
		int parent(int);
		bool isleaf(int);
		void swap(int,int);
		void display();
		int MaxHeap(int);
		int MinPartner(int);
		int MaxPartner(int);
		void Minlnsert(int);
		void Maxlnsert(int);
		void insert();
		void deletemin();
		void deletemax();
		Deap::Deap(int m,int sz)
		{
			maxsize=m;
			h=new int[m];
			size=sz;
		}
		int Deap::leftchild(int i)
		{
			return 2*i;
		}
		int Deap::rightchild(int i)
		{
			return 2*i+1;
		}
		int Deap::parent(int i)
		{
			return i/2;
		}
		bool Deap::isleaf(int i)
		{
			return ((i<=size)&&(i>size/2));
		}
		void Deap::swap(int i,int j)
		{
			int t;
			t=h[i];
			h[i]=h[j];
			h[j]=t;
		}
		void Deap::display()
		{
			cout<<"The Deaps elements are:"<<endl;
			for(int i=1;i<=size+1;i++)
				cout<<"\n"<<h[i]<<endl;
		}
		int Deap::MaxHeap(int i)
		{
			int t=i;
			while(t!=2 && t!3)
				t=t/2;
			if(t==2)
				return 0;
			else
				return 1;
		}
		int Deap::MinPartner(int p)
		{
			int powvalue=(int) ((floor(log(p)/log(2)))-1); mt partner=p-(int)(pow(2,powvalue));
			return partner;
		}
		int Deap::MaxPartner(int p)
		{
			int powvalue=(int) ((floor(log(p)/log(2)))- 1);
			int partner=p+(int)(pow(2,powvalue));
			if(partner>size-i- 1)
				partner/=2;
			return partner;
		}
		void Deap::Minlnsert(int i)
		{
			while (parent(i)!=1&&(h[parent(i)]>h[i]))
			{
				int par=parent(i);
				swap(par,i);
				i=par;
			}
		}
		void Deap::Maxlnsert(int i)
		{
			while (parent(i)!=1&&(h[parent(i)]<h[i]))
			{
				int par=parent(i);
				swap(par, i);
				i=par;
			}
		}
		void Deap::insert()
		{
			int newelt=0;
			size++;
			if(size>maxsize)
				cout<<"Deap full"<<endl;
			else
			{
				cout<<"Enter the element:"<<endl;
				cin>>newelt;
				if(size==1)
				{
					h[2]=newelt;
					return;
				}
				int p=size+1;
				h[p]=newelt;
				switch(MaxHeap(p))
				{
				case 1:
					int partner=MinPartner(p);
					if(h[partner]>h[p])
					{
						swap(p,partner);
						Minlnsert(partner);
					}
					else
						Maxlnsert(p);
					break;
				case 0:
					partner=MaxPartner(p);
					if(h[partner]<h[p])
					{
						swap(p,partner);
						Maxlnsert(partner);
					}
					else
						Minlnsert(p);
					break;
				default:
					cout<<"ERROR"<<endl;
				}
			}
		}
		void Deap::deletemin()
		{
               if(size==O)
                   cout<<"Deap empty"<<endl;
               else
               {
                   cout<<"The deleted min element is:"<<h[2]<<endl;
                   int i;
                   int p=size+1;
                   int t=h[p];
                   size--;
                   int small;
                   for( i=2;2*i<=size+1;i=small)
                   {
                       if(h[rightchild(i)]<h[leftichild(i)])
                          small=rightchild(i);
                       else
                           small=leftchild(i);
                       h[i]=h[small];
                   }
                   p=i;
                   h[p]=t;
                   for(i=2;i<=size+1;i++)
                   {
                       switch(MaxHeap(i))
                       {
                       case 1:
                           int partner=MinPartner( i);
                           if(h[partner]>h[i])
                           {
                               swap(Lpartner); I/if greater swap
                               Minlnsert(partner);
                           }
                           else
                               Maxlnsert(i);
                           break;
                       case 0:
                           partner=MaxPartner(i);
                           if(h[partnerj<h[i)
                           {
                               swap(i,partner);
                               Maxlnsert(partner);
                           }
                           else
                               Minlnsert(i):
                           break;
                       default:
					cout<<"ERROR"<<endl;
				}
			}
		}
    }
	void Deap::deletemax()
	{
        if(size==O)
            cout<<"Deap empty"<<endl;
        else
        {
            cout<<"The deleted max elt:"<<h[3]<<endl;
            int i;
            int p=size+1;
            int t=h[p];
            size--;
            int big;
            for(i=3;2*i<=size+1;i=big)
            {
                if(h[rightchild(i)]>h[leftchild(i)])
                    big=rightchild(i);
                else
                    big=leftchiId(i);
                h[i]=h[bigj;
            }
            p=i;
            h[p]=t;
            for(i=2;i<=size+1;i++)
            {
                switch(MaxHeap(i))
                {
                case 1:
                    int partner=MinPartner(i);
                    if(h[partner]>h[i])
                    {
                        swap(i,partner);
                        Minlnsert(partner);
                    }
                    else
                        Maxlnsert(i):
                    break;
                case 0:
                    partner=MaxPartner(i)
                    if(h[partnerj<h[i])
                    {
                        swap(i,partner);
                        Maxlnsert(partner);
                    }
                    else
                        Minlnsert(i);
                        break;
                default:
                    cout<<"ERROR"<<endl;
                }
            }
        }
    }
}
void main()
{
	clrscr();
	int ch=0;
	int cont=0;
	Deap h1Deap(l00,0);
	do
	{
		cout<<"DEAPS"<<"\n"<<" 1 .Insert"<<"\n"<<"2.DeleteMin"<<"\n"<<"3 .DeleteMax"<<"\n"<<"4.DispIay Deap"<<"\n"<<"5.Exit";
		cout<<"\n"<<"Enter The Choice:"<<endl;
		cin>>ch;
		if(ch==1)
			h1.Insert();
		else if(ch==2)
			h1.deletemin();
		else if(ch==3)
			h1.deletemax();
		else if(ch==4)
			h1.display();
		else if(ch==5)
			break;
		else
            cout<<"Enter the correct choice"<<endl;
            cout<<"Press '1’ to continue:"<<endl;
			cin>>cont;
	}while(cont==l);
	getch();
}
