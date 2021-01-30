# Drawing-Trees-Using-TR-algorithm


# Ubuntu

First Install OpenGL -> sudo apt-get install freeglut3-dev

Compile Using        -> g++ main.cpp linecircle.cpp tidieralgo.cpp -lglut -lGL -lGLU 

Run                  -> ./a.out

# Windows

Follow the Steps Given here: https://www.geeksforgeeks.org/getting-started-with-opengl/

Neat Trees using TR Algorithm Rendered using OpenGL

@mainpage Results, Issues and Analysis

## Made By:
### 1. Debmeet Banerjee     2018A7PS0385H 
### 2. Anirudh Sood         2018A7PS0673H
### 3. Sri Chand Gamguri    2017A7PS0272H

## Simplifying The TR Algorithm---

"Tidier drawings of trees"-drawings using  as little space as possible while satisfying certain aesthetics-


Aesthetic 1: Nodes at the same level of the tree should lie along a straight line, and the straight lines defining the levels should be parallel.

Aesthetic 2: A left son should be positioned to the left of its father and a right son to the right.

Aesthetic 3: A father should be centered over its sons.

Aesthetic 4: A tree and its mirror image should produce drawings that are reflections of one another; moreover, a subtree should be drawn the same way regardless of where it occurs in the tree.



Goal:2 subtrees of a node should be formed independently, and then placed as close together as possible. 

     Produce very pleasing drawings in general,but the drawings can be wider than the minimum possible under the 4 aesthetics
     


## Procedure:

Work is done by recursive postorder traversal procedure. During the traversal the procedure performs three tasks at each node T: 

1. it determines how close together the subtrees of T can be placed; 
2. it keeps track of nodes that may need to be threaded later;
3. it inserts a thread if one is required.

			
## Detailed Procedure:


### Task 1: Done using While Loop: It scans down the right contour of the left subtree and the left contour of the right subtree of selected node T, 

															computing the distance between them,

															pushing them apart when necessary. 

															Variables L and R are initially set to point to the left and right son of T. 

															MINSEP is a parameter that gives the minimum separation allowed between two nodes on a level; 

															CURSEP holds the separation at the current level. 

															ROOTSEP has the required separation distance for the sons of T so that their subtrees will have a separation of at least MINSEP at all levels.

															LOFFSUM and ROFFSUM accumulate the total offset of the current L and R from the root;

															(this information is needed to compute offsets of threaded nodes)


### Task 2 : keeping track of the leftmost and rightmost nodes on the lowest level of the subtree; only these nodes are threaded if needed. 

Information of extreme descendants are stored in this format:
ADDR : LINK;									(* address *)
OFF : INTEGER;								(* offset from root of subtree *)
LEV : INTEGER									(* tree level *)


### Task 3 : Threading, is needed only if the subtrees joined at the current node have different heights and neither is empty. 

 			   The thread is stored in the left link field if the node to which it points is to its left, and in the right link field otherwise; 

 			   This makes the threads transparent as the subtrees are pushed apart. This  is why offsets in fathers rather than sons.


SETUP     :  Procedure SETUP assigns relative x coordinates to all nodes during a postorder traversal.

PETRIFY  :  Procedure PETRIFY converts relative positionings to absolute coordinates and erases the threads.


## Issues Faced While Doing the Assignment

1. Unfamiliarity with OpenGL, leading to various issues(flickering, random points displayed etc)
2. Clearing the input buffer bit by mistake
3. Not setting different colors for foreground and background resulting in blank screen
4. Issues in understanding how the code needs to be commented for Doxygen to run properly

## Help Taken from
1. Various Google searches
2. Few snippets of code from StackOverflow ,GeeksForGeeks 
3. Some funcions from a GitHub repository
4. A few Friends and Seniors
