# 완전탐색 > 소수 찾기 문제풀이 (#13)
# 출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges

def primes_up_to(number):
    sieve = [ False, False ] + [ True ] * (number-1)
    for k in range(2, int(number**0.5) + 1):
        if sieve[k]:
            sieve[2*k::k] = [ False ] * (number//k - 1)
    return [ k for (k, value) in enumerate(sieve) if value ]

def possibility(current, numbers, primes):    
    result = 0
    if len(numbers) == 0: return 0
    for number in set(numbers):
        new = current + number
        if int(new) == 0: continue
        if int(new) in primes: result += 1
        p = numbers.index(number)
        numbers_left = numbers[:p] + numbers[p+1:]
        result += possibility(new, numbers_left, primes)
    return result

def solution(numbers):
    primes = primes_up_to(int('9'*len(numbers)))
    number_list = [ n for n in numbers ]
    return possibility('0', number_list, primes)