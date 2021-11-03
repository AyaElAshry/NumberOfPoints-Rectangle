# Number of Points in each Rectangle

## Problem Formulation:
You will have two sets. 
* The first set contains rectangles, they may overlap or not. 
* The second set contains points.

==> Example:  
![github](https://user-images.githubusercontent.com/64116564/140199262-39bb9e05-2e2b-4c57-ab1d-61e00247e312.png)

Rectangle 1 -> 2 points  
Rectangle 2 -> 2 points   
Rectangle 3 -> 3 points  
Rectangle 4 -> 1 point  

## Solution:  
Implement at least two algorithms with different complexity to find the count of points that each rectangle contain.  
**Note:** points on rectangle’s edge included.  
## Input:
* Text file contains the coordinates of rectangles under title “RECTANGLES”, the coordinates of points under title “POINTS”
* In rectangles section, each line contains coordinates of one rectangle in format (id x1 y1 x2 y2).
![github2](https://user-images.githubusercontent.com/64116564/140199798-66b8ec53-92ed-45a3-9808-0c16482515c7.png)
* In points section, each line contains coordinates of one point in format (id x y).  
![hub1](https://user-images.githubusercontent.com/64116564/140199724-f3d80aae-3f54-4a9c-8ed7-185dadda6a3d.png)
* LONG_MIN <= coordinates <= LONG_MAX
* You have five data sets for testing.  
https://drive.google.com/drive/folders/1Dzw4xd_vv_aU_xknHj6i4Yug-wzJGfU3
## Output
* One text file for each test case contains in each line “rectangle_id points_count”
* Output should be sorted in ascending order by rectangle id.   
==> Example:   
![hub2](https://user-images.githubusercontent.com/64116564/140200046-46d7b7db-4d79-479f-9b32-b57a4c5e63f7.png)
* Output files should be named as : results_1, results_2, … results_5
