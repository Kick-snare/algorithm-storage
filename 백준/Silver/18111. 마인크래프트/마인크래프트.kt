private fun readStrings() = readln().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    var maxHeight = 0
    var minHeight = 300
    val (n, m, b) = readInts()
    val arr = Array(n) { IntArray(m) }

    repeat(n) { i ->
        readln().split(' ').forEachIndexed { j, h ->
            val height = h.toInt()
            maxHeight = maxHeight.coerceAtLeast(height)
            minHeight = minHeight.coerceAtMost(height)
            arr[i][j] = height
        }
    }

    var candidate = Pair(Int.MAX_VALUE, 0 )

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