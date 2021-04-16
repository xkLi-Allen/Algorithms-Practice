#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<queue>
#include<string>
#include<stack>
#include<time.h>

using namespace std;


// 1，栈初始化
// 2，获得起点，将起点标识为已走过，将起点入栈
// while（栈非空）{
//   取栈顶元素vt
//   如果vt周围有为走过的节点vf，则：
//       将vf改为已走
//       vf入栈
//   没有能走的节点，vt出栈
// }


struct Node
{
    int x;
    int y;
    bool walked;
    int g;
    int f;//f = g+h
    int h;
    Node* parents;
};

int main() {
    
    vector<vector<Node>> migong;//创建二维迷宫组
    for (int i = 0; i < 5; i++) {
        vector<Node> hang;
        for (int j = 0; j < 5; j++) {
            int ii;
            cin >> ii;
            Node node{ i,j,ii };
            hang.push_back(node);
        }

        migong.push_back(hang);
    }
    
    
    /*-----------------------------------dfs----------------------------------------------*/
    vector<vector<Node>> migong2 = migong;

    stack<Node*> f;
    f.push(&migong2[0][0]);
    migong2[0][0].walked = true;
    while (!f.empty()) {
        Node *vt = f.top();
        bool can = true;
        if (vt->x >= 1) {
            Node *vf = &migong2[vt->x - 1][vt->y];
            if (vf->walked == false) {
                vf->parents = vt;
                vf->walked = true;
                if (vf == &migong2[4][4]) {
                    break;
                }
                f.push(vf);
                can = false;
            }
        }
        if (vt->x <=3) {
            Node *vf = &migong2[vt->x + 1][vt->y];
            if (vf->walked == false) {
                vf->parents = vt;
                vf->walked = true;
                if (vf == &migong2[4][4]) {
                    break;
                }
                f.push(vf);
                can = false;
            }
        }
        if (vt->y >= 1) {
            Node *vf = &migong2[vt->x][vt->y - 1];
            if (vf->walked == false) {
                vf->parents = vt;
                vf->walked = true;
                if (vf == &migong2[4][4]) {
                    break;
                }
                f.push(vf);
                can = false;
            }
        }
        if (vt->y <= 3) {
            Node *vf = &migong2[vt->x ][vt->y + 1];
            if (vf->walked == false) {
                vf->parents = vt;
                vf->walked = true;
                if (vf == &migong2[4][4]) {
                    break;
                }
                f.push(vf);
                can = false;
            }
        }

        if (can) {
            f.pop();
        }

    }

    




    vector<Node*> fin2;
    Node*bb = &migong2[4][4];
    while (true) {

        fin2.push_back(bb);
        if (bb == &migong2[0][0]) {
            break;
        }
        bb = bb->parents;

    }

    

    int count2 = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << migong2[i][j].walked;
            if (migong2[i][j].walked)count2++;
        }
        cout << endl;
    }
    reverse(fin2.begin(), fin2.end());




    for (int i = 0; i < fin2.size(); i++) {
        cout << fin2[i]->x <<" "<< fin2[i]->y<< endl;
    }

    return 0;
}


