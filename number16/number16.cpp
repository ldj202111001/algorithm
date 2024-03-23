#include <stdio.h>


// 16번 그래프에 나와 있는 맵을 그래프(인접행렬)화 
// 영역 = 정점(vertex), 영역들 간의 인접 유무 = 간선(edge)
// 무방향 그래프, 가중치 없음 (인접유무만 구현), (0: 인접하지 않음, 1: 인접함)     
int graph[7][7] = {
 {0, 1, 0, 0, 0, 0, 0}, // A
 {1, 0, 1, 1, 1, 1, 0}, // B`
 {0, 1, 0, 0, 0, 1, 1}, // C
 {1, 1, 0, 0, 1, 0, 0}, // D
 {0, 1, 0, 1, 0, 1, 1}, // E
 {0, 1, 1, 0, 1, 0, 1}, // F
 {0, 0, 1, 0, 1, 1, 0}  // G
};

// 각 영역에 칠해진 색깔
//  (0은 무색, 아직 정하지 않음)
// A: 0, B: 1, C: 2, D: 3, E: 4, F: 5, G: 6}
int area[7] = { 0, 0, 0, 0, 0, 0, 0 };

int find_color(int a);   // 해당 영역을 파라미터로 넣으면 해당 영역에 인접한 영역들을 탐색비교해 칠할 수 있는 색깔을 정하는 함수

int main()
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            printf(" %d ", graph[i][j]);
        }
        printf("\n");
    }    // 그래프 출력 테스트

    for (int i = 0; i < 7; i++)
    {
        area[i] = find_color(i);
    }

    for (int i = 0; i < 7; i++)
    {
        printf("%d", area[i]);
    }

}

int find_color(int a)
{
    bool find = true;    // bool형 find : 칠하고싶은 색깔이 인접한 영역의 색깔과 같을때 True로 됨

    int color = 0;

    while (1)
    {
        if (find == true)
        {
            color++;
            find = false;
        }

        for (int k = 0; k < 7; k++)
        {
            if (graph[a][k] == 1) // 인접하다면
            {
                if (area[k] == color) // 인접한 영역중 해당 색깔이 있다면
                    find = true;
            }
        }

        if (find == false)
            break;

    }

    return color;


}