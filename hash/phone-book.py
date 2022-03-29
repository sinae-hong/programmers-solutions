# 해시 > 전화번호 목록 문제풀이 (#12)
# 출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges

def solution(phone_book):
    phone_book.sort()
    
    for p, number in enumerate(phone_book[:-1]):
        if phone_book[p+1].find(number) == 0:
            return False
                    
    return True