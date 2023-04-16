private fun readStrings() = readln().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    var maxHeight = 0
    var minHeight = 257
    var heightSum = 0
    val (n, m, b) = readInts()
    val arr = Array(n) { IntArray(m) }

    repeat(n) { i ->
        readln().split(' ').forEachIndexed { j, h ->
            val height = h.toInt()
            maxHeight = maxOf(maxHeight, height)
            minHeight = minOf(minHeight, height)
            arr[i][j] = height
            heightSum += height
        }
    }

    val avgHeight = (heightSum + b) / (n * m)
    maxHeight = minOf(maxHeight, avgHeight)
    var candidate = Pair(Int.MAX_VALUE, 0)

    for(height in minHeight..maxHeight) {
        var stackCount = 0
        var popCount = 0

        for(row in arr) {
            for(target in row) {
                when {
                    target < height -> stackCount += height - target
                    target > height -> popCount += target - height
                }
            }
        }

        val time = stackCount + popCount * 2

        if(b + popCount >= stackCount && time <= candidate.first)
            candidate = Pair(time, height)
    }

    with(candidate) { print("$first $second") }
}