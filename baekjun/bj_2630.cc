#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <vector>
using namespace std;
static int zeroCount = 0;
static int oneCount = 0;
class QuadTree {
    public:
        QuadTree(vector<vector<int>> &input, int flag, int size) {
            m_colorFlag = flag;
            m_2dArray = input;
            LH = nullptr;
            RH = nullptr;
            LL = nullptr;
            RL = nullptr;
            m_size = size;
            this->divAndConquer();
        }
        static int checkChildColor(vector<vector<int>> &input, int size);

    private:
        vector<vector<int>>& mkLH(vector<vector<int>> &input, vector<vector<int>> &output);
        vector<vector<int>>& mkRH(vector<vector<int>> &input, vector<vector<int>> &output);
        vector<vector<int>>& mkLL(vector<vector<int>> &input, vector<vector<int>> &output);
        vector<vector<int>>& mkRL(vector<vector<int>> &input, vector<vector<int>> &output);

        void divAndConquer();
        vector<vector<int>> m_2dArray;
        int m_colorFlag;
        int m_size;
        QuadTree* LH;
        QuadTree* RH;
        QuadTree* LL;
        QuadTree* RL;
};

int QuadTree::checkChildColor(vector<vector<int>> &input, int size){
    int tmp = input[0][0];
    for(int i = 0; i < size; i++ ){
        for(int j = 0; j < size; j++){
            if(input[i][j] != tmp){
                return 2;
            }
        }
    }
    return tmp;
}

vector<vector<int>>& QuadTree::mkLH(vector<vector<int>> &input, vector<vector<int>> &output){
    for(int i = 0; i < (m_size / 2); i++){
        for(int j = 0; j < (m_size / 2); j++){
            output[i][j] = input[i][j];
        }
    }
    return output;
}
vector<vector<int>>& QuadTree::mkRH(vector<vector<int>> &input, vector<vector<int>> &output){
    for(int i = 0; i < (m_size / 2); i++){
        for(int j = 0; j < (m_size / 2); j++){
            output[i][j] = input[i][(m_size / 2) + j];
        }
    }
    return output;
}

vector<vector<int>>& QuadTree::mkLL(vector<vector<int>> &input, vector<vector<int>> &output){
    for(int i = 0; i < (m_size / 2); i++){
        for(int j = 0; j < (m_size / 2); j++){
            output[i][j] = input[(m_size / 2) + i][j];
        }
    }
    return output;
}

vector<vector<int>>& QuadTree::mkRL(vector<vector<int>> &input, vector<vector<int>> &output){
    for(int i = 0; i < (m_size / 2); i++){
        for(int j = 0; j < (m_size / 2); j++){
            output[i][j] = input[(m_size / 2) + i][(m_size / 2) + j];
        }
    }
    return output;
}

void QuadTree::divAndConquer(){
    if(m_colorFlag == 0){
        zeroCount++;
        return;
    }
    else if (m_colorFlag == 1) {
        oneCount++;
        return;
    }
    //  if(m_size  == 1)
    //    return;
    vector<vector<int>> output;
    output.resize( m_size / 2, vector<int>( m_size / 2, -1));
    LH = new QuadTree(mkLH(m_2dArray, output), checkChildColor(mkLH(m_2dArray, output), m_size / 2), m_size / 2);
    RH = new QuadTree(mkRH(m_2dArray, output), checkChildColor(mkRH(m_2dArray, output), m_size / 2), m_size / 2);
    LL = new QuadTree(mkLL(m_2dArray, output), checkChildColor(mkLL(m_2dArray, output), m_size / 2), m_size / 2);
    RL = new QuadTree(mkRL(m_2dArray, output), checkChildColor(mkRL(m_2dArray, output), m_size / 2), m_size / 2);

}

int main(){

    int N;
    cin >> N;
    vector<vector<int>> input;
    input.resize(N, vector<int>(N, -1));
    for (int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> input[i][j];
        }
    }

    int flag = QuadTree::checkChildColor(input, N);

    QuadTree* quadTree = new QuadTree(input, flag, N);

    cout << zeroCount << endl;
    cout << oneCount << endl;
    delete quadTree;

    return 0;
}