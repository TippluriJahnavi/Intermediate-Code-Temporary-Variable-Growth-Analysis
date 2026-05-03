Temp_Variable_Growth_Analyzer

HoT Skill – Temporary Variable Growth Analysis

Overview

This project implements a Temporary Variable Growth Analyzer to evaluate intermediate code generated during compilation. The objective is to derive a meaningful optimization metric from raw three-address code (TAC) instructions to assess code generation efficiency.

Problem Statement

During intermediate code generation, the compiler produces temporary variables such as t1, t2, t3, etc., to store intermediate results. However, raw TAC instructions do not clearly indicate whether excessive temporary variables are being generated.

Therefore, a feature called Temp_Variables_Per_Block is computed to measure temporary variable growth in each basic block.

Approach
1. Data Processing
Number of basic blocks is taken as input
Number of instructions per block is recorded
Instructions are read line by line
Tokens are extracted using string parsing
Temporary variables are identified using pattern matching (t followed by digits)
2. Feature Computation

Temporary Variable Count is calculated using:

Temp_Variables_Per_Block = Count of tokens matching t<number>

This quantifies intermediate variable growth within each block.

3. Flag Generation

A threshold value is used to classify blocks:

Temp_Variables_Per_Block > 3  → Temp Heavy Block
Temp_Variables_Per_Block ≤ 3  → Normal Block

This converts numeric data into a decision indicator.

4. Additional Analysis
Displays block-wise temporary count
Identifies optimization-prone blocks
Highlights potential register pressure
Supports compiler optimization decisions
Implementation Details

Language Used: C

Concepts Used:

Arrays
Loops
String tokenization (strtok)
Character validation (isdigit)
Conditional statements
Formatted output using printf()
Sample Input
Enter number of basic blocks: 2
Enter number of instructions in Block 1: 3
t1 = a + b
t2 = t1 * c
x = t2 + d

Enter number of instructions in Block 2: 4
t3 = p + q
t4 = t3 - r
t5 = t4 * s
y = t5 + z
Sample Output
Block 1 Analysis:
Temp_Variables_Per_Block = 3
Is_Temp_Heavy = NO

Block 2 Analysis:
Temp_Variables_Per_Block = 5
Is_Temp_Heavy = YES
Threshold Justification

A threshold value of 3 temporary variables per block is selected based on optimization standards in compiler design. Blocks exceeding this value may indicate:

Excessive intermediate computations
Higher register usage
Increased memory overhead
Reduced execution efficiency

Thus, such blocks are marked as Temp Heavy for further optimization.

Real-World Relevance

Temporary Variable Growth Analysis can be used in:

Compiler optimization modules
Static code analysis tools
Performance evaluation systems
Register allocation strategies

It helps identify inefficient intermediate code generation and improves overall compiler performance.

Files Included
RA2311026050242_Tippluri Jahnavi_HoT.c
RA2311026050242_Tippluri Jahnavi.png
RA2311026050242_Tippluri Jahnavi.pdf

Conclusion

This project demonstrates how raw intermediate code can be transformed into meaningful performance metrics using feature engineering and conditional logic. The Temporary Variable Growth metric provides a structured approach to detect inefficiencies in code generation and supports optimization-aware compiler design.
