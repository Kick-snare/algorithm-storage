import kotlin.math.max

data class App(val memory: Int, val cost: Int) {
    constructor(pair: Pair<Int, Int>): this(pair.first, pair.second)
}

fun main() {
    fun readInts() = readln().split(" ").map(String::toInt)
    val (n, m) = readInts()
    val (memories, costs) = readInts() to readInts()
    val costSum = costs.sum()
    val apps = memories.zip(costs).map(::App)
    val dp = IntArray(costSum+1) { 0 }
    
    for((appMemory, appCost) in apps) {
        for(cost in costSum downTo 1) {
            if(cost >= appCost) {
                dp[cost] = max(dp[cost], dp[cost - appCost] + appMemory)
            }
        }
    }
    
    for(cost in 0..costSum) {
        if(dp[cost] >= m) {
            println(cost)
            break
        }
    }
}