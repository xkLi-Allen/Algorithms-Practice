#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;

// 1，将起点推入队列中；
// 2，将起点标识为已走过；
// while（队列非空）{
//   3，取队列首节点vt，并从队列中弹出；
//   4，探索上面取出得节点的周围是否有没走过的节点vf，如果有将所有能走的vf的parents指向vt，并将vf加入队列
//     （如果vf等于终点，说明探索完成，退出循环）。
// }
// 如果队列为空自然跳出，说明无路可达终点。


struct Node{
    //自身处于组内的位置
    int xx ;
    int yy;
    bool qiang;//是否是墙
    bool walked;//是否走过
    Node *parents;//指向父节点的指针
};

int main(){
    int id = 0;
    queue<Node*> bfs;//创建Node指针队列
    vector<vector<Node>> graph;//创建图
    for (int i = 0; i < 5; i++){
        vector<Node> hang;
        for (int j = 0; j < 5; j++){
            int ii;
            cin >> ii;
            Node node {i,j,ii,false};
            hang.push_back(node);
        }

        graph.push_back(hang);
    }

    int ax[4] = {-1, 1, 0, 0};
    int by[4] = {0, 0, 1, -1};

    bfs.push(&graph[0][0]);
    graph[0][0].walked = true;

    Node *vt;//等下指向父节点的指针
    Node *vf;//等下指向父节点引申出的子节点

    while(!bfs.empty()){
        vt = bfs.front();
        bfs.pop();
        if ((*vt).xx >= 1){//查询左节点是否可以
            vf = &graph[(*vt).xx + ax[0]][(*vt).yy + by[0]];
            if(!(*vf).qiang && !(*vf).walked){
                bfs.push(vf);
                (*vf).walked = true;
                (*vf).parents = vt;//子节点指向父节点
                if ((*vf).xx == 4 && (*vf).yy == 4){
                    break;//如果是终点节点，结束寻找，跳出循环。
                }
            }
        }

        if((*vt).xx <= 3){//查询右节点是否可以
            vf = &graph[(*vt).xx + ax[1]][(*vt).yy + by[1]];
            if (!(*vf).qiang && !(*vf).walked){
                bfs.push(vf);
                (*vf).walked = true;
                (*vf).parents = vt;
                if ((*vf).xx == 4 && (*vf).yy == 4){
                    break;
                }
            }
        }

        if((*vf).yy <= 3){//查询下节点是否可以
            vf = &graph[(*vt).xx + ax[2]][(*vt).yy + by[2]];
            if (!(*vf).qiang && !(*vf).walked){
                bfs.push(vf);
                (*vf).walked = true;
                (*vf).parents = vt;
                if ((*vf).xx == 4 && (*vf).yy == 4){
                    break;
                }
            }
        }

        if ((*vt).yy >= 1) {//查询上节点是否可以
            vf = &graph[(*vt).xx + ax[3]][(*vt).yy + by[3]];
            if (!(*vf).qiang && !(*vf).walked) {
                bfs.push(vf);
                (*vf).walked = true;
                (*vf).parents = vt;
                if ((*vf).xx == 4 && (*vf).yy == 4) break;
            }
        }
    }

    vector<Node*> fin;
    while(true){
        fin.push_back(vf);
        vf = (*vf).parents;
        if ((*vf).xx == 0 && (*vf).yy == 0){
            fin.push_back(vf);
            break;
        }
    }

    for (vector<Node*> :: iterator cur = fin.end() - 1; cur + 1 != fin.begin(); cur--){
        cout << (*cur) -> xx << "," << (*cur) -> yy << endl;

    }
}