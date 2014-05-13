int CBoard::AlphaBeta(int data[][15], int Depth, int color, long Alpha, long Beta, int *AIPos)
{
	int score;
	if (Depth == 0)
		return evaluate(data,color); // 叶子节点返回估值
	if (color == BLACK) // 如果该玩家走
	{ // turn=PLAYER表示极小值的节点
		for (int i=0;i<15;i++) 
		{
			for(int j = 0; j < 15; j++)// 对每一可能的走法m
			{
				// 生成新节点

				if(data[i][j] == EMPTY)
				{
					data[i][j] = color;
					score = AlphaBeta(data, Depth-1, WHITE, Alpha, Beta, AIPos); // 递归搜索子节点
					data[i][j] = EMPTY; // 撤销搜索过的节点
					if (score < Beta)
					{
						Beta = score ; // 取极小值
						if (Alpha >= Beta)
							return Beta ; // Alpha剪枝,抛弃后继节点
					}
				}	
			}
		}
		return Beta ; // 返回最小值
	}

	else
	{ // 取极大值的节点 
		//m_color = COMPUTER
		for (int i=0; i < 15; ++i) // 对每一可能的走法m
		{
			for(int j = 0; j < 15; ++j)
			{
				// 生成新节点
				if(data[i][j] == EMPTY)			//i = 1
				{
					data[i][j] = color;			//Board[1] = COMPUTER
					score =AlphaBeta(data, Depth-1, BLACK, Alpha, Beta, AIPos) ; // 递归搜索子节点

					data[i][j] = EMPTY; // 撤销搜索过的节点
					if (score > Alpha)
					{
						if (Depth == 2) //是的，Depth == 3
						{
							AIPos[XPOS] = i;
							AIPos[YPOS] = j;
						}

						Alpha = score ;			//	取极大值Alpha = -18
						if (Alpha >= Beta)
							return Alpha ; // Beta剪枝,抛弃后继节点
					}
				}
			} //i = 1, Alpha = -18，Beta = -18  无剪枝过程
			// i = 2,
		}
		return Alpha ; // 返回最大值 
	}
}
