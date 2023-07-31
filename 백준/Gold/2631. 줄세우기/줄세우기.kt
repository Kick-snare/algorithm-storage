fun main() {
    val n = readln().toInt()
    val kids = IntArray(n) { readln().toInt() }
    var answer = 0

    // 0 부터 i 번째 값까지의 LIS 크기
    val dp = IntArray(n) { 1 }

    for (i in 0 until n) {
        for (j in 0 until i) {
            if (kids[i] > kids[j]) {
                dp[i] = dp[i].coerceAtLeast(dp[j]+1)
            }
        }
        answer = answer.coerceAtLeast(dp[i])
    }

    print(n - answer)
}