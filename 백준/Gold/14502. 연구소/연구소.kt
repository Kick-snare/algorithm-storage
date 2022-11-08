import java.lang.Double.max
import java.util.*
import kotlin.math.max

private lateinit var map: Array<IntArray>
private val dx = intArrayOf(-1, 0, 1, 0)
private val dy = intArrayOf(0, -1, 0, 1)
private var N = 0
private var M = 0
private val virusList = ArrayList<Virus>()
private var answer = 0


fun main(args: Array<String>) {
    val sc = Scanner(System.`in`)
    N = sc.nextInt()
    M = sc.nextInt()
    map = Array(N + 2) { IntArray(M + 2) }
    for (i in map.indices) {
        map[i][0] = 1 // left 벽
        map[i][M + 1] = 1 // right 벽
    }
    for (j in map[0].indices) {
        map[0][j] = 1 // top 벽
        map[N + 1][j] = 1 // bottom 벽
    }
    for (i in 1..N)
        for (j in 1..M) {
            map[i][j] = sc.nextInt()
            if (map[i][j] == 2)
                virusList.add(Virus(i, j)) // virusList 에 추가
        }
    dfs(0)
    println(answer)
}

private fun dfs(count: Int) {
    if (count == 3) {
        val tmp = Array(N + 2) { IntArray(M + 2) }
        for (i in 0..N + 1)
            for (j in 0..M + 1) tmp[i][j] = map[i][j]

        for (virus in virusList) start(virus, tmp) // tmp map 에 바이러스 살포
        countSafeArea(tmp)
        return
    }

    for (i in 1..N)
        for (j in 1..M)
            if (map[i][j] == 0) {
                map[i][j] = 1
                dfs(count + 1)
                map[i][j] = 0
            }
}

private fun start(virus: Virus, map: Array<IntArray>) {
    // bfs
    val queue: Queue<Virus> = LinkedList()
    queue.offer(virus)
    while (!queue.isEmpty()) {
        queue.poll().run {
            for (i in 0..3) {
                val x2 = x + dx[i]
                val y2 = y + dy[i]
                if (map[x2][y2] == 0) {
                    map[x2][y2] = 2
                    queue.offer(Virus(x2, y2))
                }
            }
        }
    }
}

private fun countSafeArea(map: Array<IntArray>) {
    var count = 0
    for (i in 1..N)
        for (j in 1..M)
            if (map[i][j] == 0) count++

    answer = max(answer, count)
}

data class Virus(var x: Int, var y: Int)