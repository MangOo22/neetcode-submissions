public class Solution {
    PriorityQueue<int, int> maxHeap = new(
        Comparer<int>.Create((a, b) => b.CompareTo(a))
    );

    public int LastStoneWeight(int[] stones) {
        foreach(int stone in stones) {
            maxHeap.Enqueue(stone, stone);
        }

        while(maxHeap.Count > 1) {
            int res = findTwoHeaviestStones();
            if (res > 0) {
                maxHeap.Enqueue(res,res);
            }
        }

        return maxHeap.Count == 1 ? maxHeap.Peek() : 0;

    }

    private int findTwoHeaviestStones() {
        int x = maxHeap.Dequeue();
        int y = maxHeap.Dequeue();

        return x - y;
    }
}
