import java.util.StringTokenizer

private fun readStrings() = readln().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

data class Candidate(
    val time: Int,
    val height: Int,
) : Comparable<Candidate> {
    override fun compareTo(other: Candidate): Int {
        return if(time == other.time) height - other.height
        else other.time - time
    }
}

fun main() {
    var maxHeight = 0
    var minHeight = 300
    val (n, m, b) = readInts()
    val arr = Array(n) { IntArray(m) }

    repeat(n) { i ->
        val st = StringTokenizer(readln())
        repeat(m) { j ->
            val height = st.nextToken().toInt()
            maxHeight = maxHeight.coerceAtLeast(height)
            minHeight = minHeight.coerceAtMost(height)
            arr[i][j] = height
        }
    }

    var candidate = Candidate(987654321, 0 )

    for(height in minHeight..maxHeight) {
        var stackCount = 0
        var popCount = 0

        for(i in 0 until n) {
            for(j in 0 until m) {
                val target = arr[i][j]
                when {
                    target < height -> stackCount += height - target
                    target > height -> popCount += target - height
                }
            }
        }

        val time = stackCount + popCount * 2

        if(b + popCount >= stackCount)
            candidate = candidate.coerceAtLeast(Candidate(time, height))
    }

    with(candidate) { print("$time $height") }
}