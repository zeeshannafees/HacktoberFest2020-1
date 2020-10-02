public class Solution {
    public ArrayList<Integer> getRow(int n) {

		ArrayList<Integer> ans = new ArrayList<Integer>();

		ans.add(1);

		for (int r = 1; r <= n; r++) {
			int val = ((n - r + 1) * ans.get(r - 1)) / r;
			ans.add(val);
		}

		return ans;

	}

}
