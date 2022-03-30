# 완전탐색 > 소수 찾기 문제풀이 (#13)
# 출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges

def sieve_for_primes(limit):
    sieve = [ False, False ] + [ True ] * (limit-1)
    for k in range(2, int(limit**0.5) + 1):
        if sieve[k]:
            sieve[2*k::k] = [ False ] * (limit//k - 1)
    return sieve

def possibility(current, numbers, sieve):    
    result = 0
    if len(numbers) == 0: return 0
    for number in set(numbers):
        new = current + number
        if int(new) == 0: continue
        if sieve[int(new)]: result += 1
        p = numbers.index(number)
        numbers_left = numbers[:p] + numbers[p+1:]
        result += possibility(new, numbers_left, sieve)
    return result

def solution(numbers):
    sieve = sieve_for_primes(int('9'*len(numbers)))
    number_list = [ n for n in numbers ]
    return possibility('0', number_list, sieve)