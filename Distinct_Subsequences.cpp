class Solution {
    public int numDistinct(String s, String t) {
        Integer[][] cache = new Integer[s.length()][t.length()];
        return getDistinct(0, 0, s, t, cache);
    }
    
    private int getDistinct(int currIndex, int matchedIndex, String s, String t, Integer[][] cache) {
                System.out.println(currIndex+" "+matchedIndex);
        if (matchedIndex == t.length()) return 1;
        if (currIndex == s.length()) return 0;
        if (cache[currIndex][matchedIndex] != null) return cache[currIndex][matchedIndex];
        
        int totalCount = 0;
        for (int i = currIndex; i < s.length(); i++) {
            if (s.charAt(i) == t.charAt(matchedIndex)) {
                totalCount += getDistinct(i + 1, matchedIndex + 1, s, t, cache);
            }
        }
        cache[currIndex][matchedIndex] = totalCount;
        return totalCount;
    }
}
