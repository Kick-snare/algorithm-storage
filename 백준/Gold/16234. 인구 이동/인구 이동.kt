import java.util.*
import kotlin.math.*

fun main() {
    fun readInts() = readln().split(' ').map{ it.toInt() }
    val (N, L, R) = readInts()
    val arr = Array(N) { IntArray(N) }

    repeat(N) { r ->
        readInts().forEachIndexed { c, v ->
            arr[r][c] = v
        }
    }
    
    
    var dayPassed = 0
    
    while(movePopulation(arr, Triple(N, L, R))) { dayPassed++ }
    
    println(dayPassed)
}

data class Union(
    val population: Int,
    val unionList: List<Pair<Int, Int>>
)

fun movePopulation(
    arr: Array<IntArray>,
    tuple: Triple<Int, Int, Int>
): Boolean {
    val (N, L, R) = tuple
    val selected = Array(N) { BooleanArray(N) { false } }
    var isMoved = false
    
    val queue: Queue<Union> = LinkedList()
    
    for(i in 0 until N) {
        for(j in 0 until N) {
            if(selected[i][j]) continue
            queue.offer(bfs(arr, selected, tuple, Pair(i, j)))
            
        }
    }
    
    while(queue.isNotEmpty()) {
        val (avg, list) = queue.poll()
        list.forEach { (y, x) ->
            if(list.size > 1) isMoved = true
            arr[y][x] = avg
        }
    }
//    println()
//    arr.forEach { println(it.contentToString()) }
//    println()
    
    return isMoved
}

fun bfs(
    arr: Array<IntArray>,
    selected: Array<BooleanArray>,
    tuple: Triple<Int, Int, Int>,
    pair: Pair<Int, Int>
): Union {
    
    val (N, L, R) = tuple
    val dx = listOf(0, 1, 0, -1)
    val dy = listOf(-1, 0, 1, 0)
    
    val unionList = mutableListOf<Pair<Int, Int>>()
    var sum = 0
    
    val queue : Queue<Pair<Int, Int>> = LinkedList()
    queue.offer(pair)
    
    selected[pair.first][pair.second] = true
    
    while(queue.isNotEmpty()) {
        
        unionList.add(queue.peek())
        val (y, x) = queue.poll()
//        println("($y,$x) ${arr[y][x]}")
        
        sum += arr[y][x]
            
        for(i in 0..3) {
            val newPair = Pair(y + dy[i], x + dx[i])
            
            if(
                isIn(newPair.first, newPair.second, N) &&
                abs(arr[newPair.first][newPair.second] - arr[y][x]) in L..R
            ) {
//                println("new >> ${Pair(y, x)} $newPair ${selected[newPair.first][newPair.second]}")
                
                if(!selected[newPair.first][newPair.second]) { 
                    selected[newPair.first][newPair.second] = true
                    queue.offer(newPair)
                }
            }
        }
    }
//    println()
    return Union(sum / unionList.size, unionList)
}

fun isIn(y: Int, x: Int, N: Int) = (x in 0 until N) && (y in 0 until N)