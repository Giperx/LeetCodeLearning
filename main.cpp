//
// Created by Giperx on 2022/9/8.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;
//���ܾ���
class Solution {
public:
    //
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int ro = mat.size(), col = mat[0].size(); // �С���
        int sz = ro * col; //matԪ���ܸ���
        if (sz != r * c) return mat;
        vector<vector<int>> res(r, vector<int>(c));
        int cnt = 0; //����
        for(int i = 0; i < r; i ++){
            for(int j = 0; j < c; j ++){
                res[i][j] = mat[cnt / col][cnt % col];
                cnt++;
            }
        }
        return res;
    }
};

int main(){
   vector<int> tmp = {'1', '2', '3'};
   stack<int> s1;
   s1.push(1);
   s1.push(2);
   s1.top();
   int i = (1 + 3 + 1)/2;
   cout << i << endl;
   unordered_map<int, int> map1;
   map1[1] = 2;
   cout << map1[1] << endl;
   unordered_map<int, int> map2 = map1;
   map1[1] = 1;
    cout << map1[1] << endl;
   cout << map2[1] << endl;
    int *cnt1 = new int[26]();
    int tmp1 = 0x7fffffff;
    cout << tmp1 << endl;
    string s = "";
    cout << 'a' - 'A' << endl;
    cout << s.size() << endl;
    cout << s.length() << endl;
    return 0;
}
//acwing1212�ع�ȡ��
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N = 55, MOD = 1000000007;
int n , m, k;//n��m�� �����k������
int w[N][N];//�����ֵ
int f[N][N][13][14];// �ӣ�1��1������i��j�������k�������������ֵΪz

int main(){
    scanf("%d%d%d",&n, &m, &k);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            scanf("%d" , &w[i][j]);
            w[i][j] ++;
        }
    //��ʼ����һ�������벻��
    f[1][1][1][w[1][1]] = 1;
    f[1][1][0][0] = 1;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            if(j == 1 && i == 1) continue;

            for(int u =0 ; u <= k; u++)
                for(int v = 0; v <= 13; v++){
                    int &val = f[i][j][u][v];
                    //��ȡ
                    val = (val + f[i][j - 1][u][v]) % MOD;
                    val = (val + f[i - 1][j][u][v]) % MOD;

                    //ȡ
                    if(u > 0 && w[i][j] == v){
                        for(int c = 0; c < v; c++){
                            val = (val + f[i][j - 1][u - 1][c]) % MOD;
                            val = (val + f[i - 1][j][u - 1][c]) % MOD;
                        }
                    }
                }

        }
    int res = 0;
    for(int i = 0; i <= 13; i++) res = (res + f[n][m][k][i]) % MOD;
    printf("%d" ,res);
    return 0;
}


 Created by Giperx on 2022/11/10.


