/* 정렬 > K번째수 문제 첫번째 풀이
출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges */

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (vector<int> command : commands)
    {
        vector<int> array_copied;
        const int start = command[0], end = command[1], target = command[2];

        for (auto index = start-1; index < end; index++)
        {
            array_copied.push_back(array[index]);
        }

        for (auto position = 0UL; position < target; position++)
        {
            for (auto compare = position+1; compare < array_copied.size(); compare++)
            {
                if (array_copied[position] > array_copied[compare])
                {
                    const int temp = array_copied[position];
                    array_copied[position] = array_copied[compare];
                    array_copied[compare] = temp;
                }
            }
        }

        answer.push_back(array_copied[target-1]);
    }

    return answer;
}
