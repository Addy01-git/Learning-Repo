public boolean array6(int[] nums, int index) {
  if (nums.length <= index){
    return false;
  }
  if (nums[index] == 6){
    return true;
  }
  return array6(nums, index+1);
}
