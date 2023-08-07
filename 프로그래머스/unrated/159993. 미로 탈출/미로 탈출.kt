import java.util.*

data class Item(
    val distance: Int,
    val point: Pair<Int, Int>
)

class Solution {
    
    var n = 0
    var m = 0
    
    val dy = listOf(-1, 0, 1, 0)
    val dx = listOf(0, 1, 0, -1)
    
    val map = Array(100) { BooleanArray(100) { false } }
    
    fun solution(maps: Array<String>): Int {
        
        n = maps.size
        m = maps.first().length
        
        var start = 0 to 0
        var lever = 0 to 0
        var exit = 0 to 0
        
        for(i in 0 until n) {
            for(j in 0 until m) {
                when(maps[i][j]) {
                    'S' -> start = i to j
                    'L' -> lever = i to j
                    'E' -> exit = i to j
                    else -> Unit
                }
                map[i][j] = maps[i][j] != 'X'
            }
        }

        
        val sl = getShorestestDistance(start, lever)
        val le = getShorestestDistance(lever, exit)
        
        if(sl==-1 || le==-1) return -1
        return sl + le
    }
    
    fun getShorestestDistance(
        startPoint: Pair<Int, Int>,
        endPoint: Pair<Int, Int>
    ) : Int {
        val (sy, sx) = startPoint
        val (ey, ex) = endPoint

        val q = LinkedList<Item>()
        q.push(Item(0, startPoint))

        val visited = Array(n) { BooleanArray(m) { false } }
        visited[sy][sx] = true
        
        while(q.isNotEmpty()) {
            val item = q.poll()
            val (cy, cx) = item.point
        
            if(cy == ey && cx == ex) return item.distance
        
            for(i in 0 until 4) {
                val (ny, nx) = cy + dy[i] to cx + dx[i]
        
                if(ny !in 0 until n || nx !in 0 until m) continue
                    
                if(map[ny][nx] && visited[ny][nx].not()) {
                    visited[ny][nx] = true
                    q.add(Item(item.distance + 1, ny to nx))
                }
            }
        }
        
        return -1
    }
}