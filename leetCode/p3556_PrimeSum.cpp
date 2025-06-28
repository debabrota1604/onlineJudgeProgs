/*
3556. Sum of Largest Prime Substrings
Given a string s, find the sum of the 3 largest unique prime numbers that can be formed using any of its substrings.

Return the sum of the three largest unique prime numbers that can be formed. If fewer than three exist, return the sum of all available primes. If no prime numbers can be formed, return 0.

A prime number is a natural number greater than 1 with only two factors, 1 and itself.

A substring is a contiguous sequence of characters within a string.

Note: Each prime number should be counted only once, even if it appears in multiple substrings. Additionally, when converting a substring to an integer, any leading zeros are ignored.

 

Example 1:

Input: s = "12234"

Output: 1469

Explanation:

The unique prime numbers formed from the substrings of "12234" are 2, 3, 23, 223, and 1223.
The 3 largest primes are 1223, 223, and 23. Their sum is 1469.
Example 2:

Input: s = "111"

Output: 11

Explanation:

The unique prime number formed from the substrings of "111" is 11.
Since there is only one prime number, the sum is 11.
 

Constraints:

1 <= s.length <= 10
s consists of only digits.
*/

class Solution {
public:
    bool isPrime(long long num) {
        if (num < 2) return false;
        if (num == 2 || num == 3) return true;
        if (num % 2 == 0 || num % 3 == 0) return false;
        for (long long i = 5; i * i <= num; i = i + 6) {
            if (num % i == 0 || num % (i + 2) == 0) return false;
        }
        return true;
    }

    long long sumOfLargestPrimes(string s) {
        set<long long, greater<long long>> unique_primes;

        for (int si = 0; si < s.size(); ++si) {
            for (int ei = si; ei < s.size(); ++ei) {
                string sub = s.substr(si, ei - si + 1);
                // Handle leading zeros
                if (sub.length() > 1 && sub[0] == '0') {
                    continue;
                }
                if (!sub.empty()) {
                    long long num = stol(sub);
                    if (isPrime(num)) {
                        unique_primes.insert(num);
                    }
                }
            }
        }

        long long sum = 0;
        int count = 0;
        for (long long prime : unique_primes) {
            sum += prime;
            count++;
            if (count == 3) {
                break;
            }
        }
        return sum;
    }
};