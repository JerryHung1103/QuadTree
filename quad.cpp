#include<iostream>
using namespace std;
#include<vector>

struct Point{
    int x,y;
};

struct QuadTree{
    Point p;
    int count=1;
    QuadTree* TopLeft=nullptr, *BotRight=nullptr,*TopRight=nullptr,*BotLeft=nullptr;
    QuadTree(Point p):p(p){}

    void insert(Point point){
        
            this->count++;
            if(point.x>this->p.x && point.y>=this->p.y){
                if(TopRight ==nullptr) TopRight=new QuadTree(point);
                else TopRight->insert(point);
            }

            else if(point.x<=this->p.x && point.y>this->p.y){
                if(TopLeft ==nullptr) TopLeft=new QuadTree(point);
                else TopLeft->insert(point);
            }

            else if(point.x<=this->p.x && point.y<=this->p.y){
                if(BotLeft ==nullptr) BotLeft=new QuadTree(point);
                else BotLeft->insert(point);
            }


            else if(point.x>this->p.x && point.y<this->p.y){
                if(BotRight ==nullptr) BotRight=new QuadTree(point);
                else BotRight->insert(point);
            } 
    }
     int rank(Point point){// return number of points smaller or eaual to the point (x,y)

            if (this->p.x == point.x && this->p.y == point.y) {
                if(BotLeft!=nullptr)
                    return 1+BotLeft->count;
               else return 1;
            }
            
            else if(point.x>this->p.x && point.y>=this->p.y){
                int ans=0;
                if(point.y==p.y ){
                      
                    if(BotLeft!=nullptr)ans+=BotLeft->count;
                    if(BotRight!=nullptr)ans+=BotRight->rank(point);
                    if(TopRight!=nullptr)ans+=TopRight->rank(point);
                }
                else{
                    if(BotLeft!=nullptr)ans+=BotLeft->count;
                    if(TopLeft!=nullptr){  
                        ans+=TopLeft->rank(point);
                    }
                    if(TopRight!=nullptr){
                        ans+=TopRight->rank(point);
                    }
                    if(BotRight!=nullptr){
                        ans+=BotRight->rank(point);
                            // cout<<BotRight->rank(point)<<endl;;
                            // cout<<"this is 4"<<endl;;
                        }
                }
                //  cout<<"ans= "<<ans<<endl;;
               return 1+ans;
            }

            else if(point.x<=this->p.x && point.y>this->p.y){
                int ans=0;

                if(point.x==p.x ){
                    if(BotLeft!=nullptr)ans+=BotLeft->rank(point);
                    if(TopLeft!=nullptr)ans+=TopLeft->rank(point);
                    ans++;
                }
                else{
                    if(BotLeft!=nullptr)ans+=BotLeft->rank(point);
                    if(TopLeft!=nullptr)ans+=TopLeft->rank(point);
                }
             
                 return ans;
            }

            else if(point.x<=this->p.x && point.y<=this->p.y){
                int ans=0;
                if(point.y==p.y)ans++;
                if(BotLeft!=nullptr)ans+=BotLeft->rank(point);
                return ans;
            }

            else if(point.x>this->p.x && point.y<this->p.y){
                int ans=0;
                if(BotRight!=nullptr)ans+=BotRight->rank(point);
                if(BotLeft!=nullptr)ans+=BotLeft->rank(point);
               return ans;
            } 
           
        }
};






int main(){
QuadTree *root=nullptr;
vector<Point> points = {{1, 2}, {3, 2}, {4, 5}, {2, 3}, {1, 4},
                             {3, 1}, {5, 2}, {2, 4}, {4, 3}, {3, 3}};
for( auto p: points){
    if(root==nullptr)root=new QuadTree(p);
    else root->insert(p);
    
}

// cout<<root->BotRight->p.y;
// cout<<endl;
// cout<<endl;

// cout<<root->search({3,2})->TopRight;
// int bug=root->rank({2,2});
// cout<<bug<<endl;
// Point print{1,4};
// cout<<root->search(print)->p.x<<endl;

//   cout<<root->fun({2,4})<<endl;  
  cout<<root->rank({4,3})<<endl;   
//   root->rank({3,4});
//             cout<<root->rank({1,4})<<endl;     
//             cout<<root->rank({3,4-1})<<endl;     
//             cout<<root->rank({2-1,3-1})<<endl;     


// int Ans= root->rank({3,4})-root->rank({2-1,4})-root->rank({3,4-1})+root->rank({2-1,3-1});
// cout<<"ans is "<<Ans<<endl;


// int ans = root->point_in_rect({2,2} ,{3,4});
// cout<<ans<<endl;

}