#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

/**
 * @brief サイコロの状態を管理する構造体
 * * faces[0]: 上面 (top)
 * faces[1]: 前面 (front)
 * faces[2]: 右側面 (right)
 * faces[3]: 左側面 (left)
 * faces[4]: 後面 (back)
 * faces[5]: 底面 (bottom)
 */
struct Dice {
    std::vector<int> faces;

    // コンストラクタ: 6つの面の値を初期化
    Dice(const std::vector<int>& initial_faces) : faces(initial_faces) {}

    /**
     * @brief 北に1回回転 (前面が上面に来る)
     */
    void roll_N() {
        int temp = faces[0];
        faces[0] = faces[1];
        faces[1] = faces[5];
        faces[5] = faces[4];
        faces[4] = temp;
    }

    /**
     * @brief 東に1回回転 (右側面が上面に来る)
     */
    void roll_E() {
        int temp = faces[0];
        faces[0] = faces[3];
        faces[3] = faces[5];
        faces[5] = faces[2];
        faces[2] = temp;
    }

    /**
     * @brief 垂直に右回り (前面が右側面に来る)
     */
    void spin_CW() {
        int temp = faces[1];
        faces[1] = faces[2];
        faces[2] = faces[4];
        faces[4] = faces[3];
        faces[3] = temp;
    }

    /**
     * @brief 指定された上面と前面にサイコロの向きを合わせる
     * @param top_val 目標の上面の値
     * @param front_val 目標の前面の値
     */
    void set_orientation(int top_val, int front_val) {
        // まず、上面を正しい値に合わせる
        while (faces[0] != top_val) {
            if (faces[1] == top_val) { // 前面が上面にくるように回転
                roll_N();
            } else if (faces[2] == top_val) { // 右側面が上面にくるように回転
                roll_E();
            } else { // その他の面を上面に合わせるための回転
                roll_N();
                roll_N();
            }
        }
        
        // 次に、上面を固定したまま前面を正しい値に合わせる
        while (faces[1] != front_val) {
            spin_CW();
        }
    }

    /**
     * @brief 現在の右側面の値を返す
     * @return 右側面の値
     */
    int get_right_face() {
        return faces[2];
    }
};

int main() {
    std::vector<int> initial_faces(6);
    // 6つの面の値を読み込む
    for (int i = 0; i < 6; ++i) {
        std::cin >> initial_faces[i];
    }

    int q;
    std::cin >> q;

    // q回質問に答える
    for (int i = 0; i < q; ++i) {
        int top_val, front_val;
        std::cin >> top_val >> front_val;

        // 各質問に対して、初期状態のサイコロを新しく作成
        Dice dice(initial_faces);
        
        // 指定された上面と前面にサイコロを回転させる
        dice.set_orientation(top_val, front_val);
        
        // その時点の右側面の数字を出力する
        std::cout << dice.get_right_face() << std::endl;
    }

    return 0;
}