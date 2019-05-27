#include "ThreadBinaryTree.h"

ThreadBinaryTree::ThreadBinaryTree(treemode mode) {
	treeMode = mode;
	//制造头结点
	threadTree = Empty(threadTree);
}
ThreadBinaryTree::ThreadBinaryTree(treemode mode, eletype order[], int len) {
	treeMode = mode;
	//制造头结点
	threadTree = Empty(threadTree);
	if (len == 0) cout << "Can't initialize object ThreadBinaryTree: array length is 0.\n";
	else {
		//初始化树的数据
		head()->lchild = createTreeNode(order[0], NULL, LINK, NULL, LINK);
		treeStatus.push(head()->lchild);
		int i = 1;
		while (i < len) {
			if (treeStatus.front()->lchild == NULL) treeStatus.front()->lchild = createTreeNode(order[i++], NULL, LINK, NULL, LINK);
			treeStatus.push(treeStatus.front()->lchild);
			if (i >= len) break;
			if (treeStatus.front()->rchild == NULL) treeStatus.front()->rchild = createTreeNode(order[i++], NULL, LINK, NULL, LINK);
			treeStatus.push(treeStatus.front()->rchild);
			if (i >= len) break;
			treeStatus.pop();
		}
		buildThread(head()->lchild, head(), head()->lchild);
		//将最后一个结点的右孩子指向头结点
		fetchLChildsMostRight(head())->rchild = head();
	}
}

ThreadBinaryTree::treenode ThreadBinaryTree::Empty(treenode tgt)  {
	isThreadBuilt = false;
	return (createTreeNode(0, NULL, LINK, tgt, LINK));
}
bool ThreadBinaryTree::isEmpty(treenode tgt) {
	return (tgt == NULL);
}

ThreadBinaryTree::treenode ThreadBinaryTree::createTreeNode(eletype val, treenode lchild, tag ltag, treenode rchild, tag rtag) {
	treenode add = new celltype;
	add->data = val;
	add->lchild = lchild;
	add->ltag = ltag;
	add->rchild = rchild;
	add->rtag = rtag;
	return add;
}
ThreadBinaryTree::treenode ThreadBinaryTree::head() {
	return threadTree;
}
ThreadBinaryTree::treenode ThreadBinaryTree::first() {
	if (isEmpty(head())) {
		cout << "Can't execute first: Object ThreadBinaryTree is not initialized.\n";
		return NULL;
	}
	return threadTree->lchild;
}
ThreadBinaryTree::eletype ThreadBinaryTree::data(treenode tgt) {
	return tgt->data;
}
ThreadBinaryTree::treenode ThreadBinaryTree::leftChild(treenode parent) {
	if (!isThreadBuilt) {
		cout << "Can't return leftChild: Thread is not initialized." << endl;
		return NULL;
	};
	return parent->lchild;
}
ThreadBinaryTree::treenode ThreadBinaryTree::rightChild(treenode parent) {
	if (!isThreadBuilt) {
		cout << "Can't return rightChild: Thread is not initialized." << endl;
		return NULL;
	};
	return parent->rchild;
}

void ThreadBinaryTree::leftInsert(treenode tgt, treenode add) {
	if (!isThreadBuilt) {
		cout << "Can't execute leftInsert: Thread is not built." << endl;
		return;
	}
	switch (treeMode) {
	default:
		cout << "Can't execute leftInsert: TreeMode is not correct." << endl;
		break;
	case PRE:

		break;
	case IN:
		add->rchild = tgt;
		add->rtag = THREAD;
		add->lchild = tgt->lchild;
		add->ltag = tgt->ltag;
		tgt->lchild = add;
		if (LINK == tgt->ltag) fetchLChildsMostRight(add)->rchild = add;
		tgt->ltag = LINK;
		break;
	case POST:

		break;
	}
}
void ThreadBinaryTree::rightInsert(treenode tgt, treenode add) {
	if (!isThreadBuilt) {
		cout << "Can't execute rightInsert: Thread is not built." << endl;
		return;
	}
	switch (treeMode) {
	default:
		cout << "Can't execute rightInsert: TreeMode is not correct." << endl;
		break;
	case PRE:
		/*
		treenode originalRChild = tgt->rchild;
		tgt->rchild = add;
		//add左孩子连接到tgt结点左孩子的最右结点
		if (tgt->ltag == LINK) {
			treenode lChildsMostRight = fetchLChildsMostRight(tgt);
			lChildsMostRight->rchild = add;
			add->lchild = lChildsMostRight;
		}
		else add->lchild = tgt;
		add->ltag = THREAD;
		//add的右孩子维护
		add->rchild = originalRChild;
		add->rtag = tgt->rtag;
		if (originalRChild->ltag == THREAD) originalRChild->lchild = add;
		tgt->rtag = LINK;
		*/
		break;
	case IN:
		add->lchild = tgt;
		add->ltag = THREAD;
		add->rchild = tgt->rchild;
		add->rtag = tgt->rtag;
		tgt->rchild = add;
		//找到右孩子的最左节点
		if (tgt->rtag == LINK) fetchRChildsMostLeft(add)->lchild = add;
		tgt->rtag = LINK;
		break;
	case POST:

		break;
	}
}
void ThreadBinaryTree::buildThread(treenode now, treenode pre, treenode next) {
	isThreadBuilt = true;
	switch (treeMode) {
	default:
		cout << "二叉树模式错误, 无法获取下一结点..." << endl;
		break;
	case PRE://先序线索二叉树
		//建立中间线索
		if (now->ltag == LINK && now->lchild == NULL) {
			now->ltag = THREAD;
			now->lchild = pre;
		}
		if (now->rtag == LINK && now->rchild == NULL) {
			now->rtag = THREAD;
			now->rchild = next;
		}
		//建立左侧线索
		if (now->ltag == LINK && now->lchild != NULL && now->rtag == LINK && now->rchild == NULL) buildThread(now->lchild, now, next);
		if (now->ltag == LINK && now->lchild != NULL && now->rtag == LINK && now->rchild != NULL) buildThread(now->lchild, now, now->rchild);
		//建立右侧线索
		if (now->rtag == LINK && now->rchild != NULL && now->ltag == LINK && now->lchild == NULL) buildThread(now->rchild, now, next);
		if (now->rtag == LINK && now->rchild != NULL && now->ltag == LINK && now->lchild != NULL) buildThread(now->rchild, now->lchild, next);
		break;
	case IN://中序线索二叉树
		//左孩子有东西, 继续向左搜索
		if (now->lchild != NULL) buildThread(now->lchild, pre, now);
		//左孩子为空, 建立线索
		else {
			now->ltag = THREAD;
			now->lchild = pre;
			cout << "** 测试接口(若无必要可以删除) **" << endl;
			cout << "建立线索的结点: " << now->data << endl;
			cout << "其前驱线索结点: " << pre->data << endl << endl;
		}
		//右孩子有东西, 继续向右搜索
		if (now->rchild != NULL) buildThread(now->rchild, now, next);
		//右孩子为空, 建立线索
		else {
			now->rtag = THREAD;
			now->rchild = next;
			cout << "** 测试接口(若无必要可以删除) **" << endl;
			cout << "建立线索的结点: " << now->data << endl;
			cout << "其后继线索结点: " << next->data << endl << endl;
		}
		break;
	case POST://后序线索二叉树
		//建立左侧线索
		if (now->ltag == LINK && now->lchild != NULL && now->rtag == LINK && now->rchild == NULL) buildThread(now->lchild, pre, now);
		if (now->ltag == LINK && now->lchild != NULL && now->rtag == LINK && now->rchild != NULL) buildThread(now->lchild, pre, now->rchild);
		//建立右侧线索
		if (now->rtag == LINK && now->rchild != NULL && now->ltag == LINK && now->lchild == NULL) buildThread(now->rchild, pre, now);
		if (now->rtag == LINK && now->rchild != NULL && now->ltag == LINK && now->lchild != NULL) buildThread(now->rchild, now->lchild, now);
		//建立中间线索
		if (now->ltag == LINK && now->lchild == NULL) {
			now->ltag = THREAD;
			now->lchild = pre;
		}
		if (now->rtag == LINK && now->rchild == NULL) {
			now->rtag = THREAD;
			now->rchild = next;
		}
		break;
	}
}
ThreadBinaryTree::treenode ThreadBinaryTree::fetchRChildsMostLeft(treenode now) {
	if (!isThreadBuilt) {
		cout << "Can't fetchRChildsMostLeft: Thread is not built." << endl;
		return NULL;
	}
	treenode srch = now->rchild;
	while (srch->ltag == LINK && srch->lchild != NULL) srch = srch->lchild;
	return srch;
}
ThreadBinaryTree::treenode ThreadBinaryTree::fetchLChildsMostRight(treenode now) {
	if (!isThreadBuilt) {
		cout << "Can't fetchLChildsMostRight: Thread is not built." << endl;
		return NULL;
	}
	treenode srch = now->lchild;
	while (srch->rtag == LINK && srch->rchild != NULL) srch = srch->rchild;
	return srch;
}

ostream& operator<<(ostream& out, const ThreadBinaryTree& tgt) {
	//检查是否生成了线索
	if (!tgt.isThreadBuilt) {
		out << "Can't display inner structure of this thread binary tree: Thread is not built.\n";
		return out;
	}
	ThreadBinaryTree::treenode srch;
	//判断该类对象内存储二叉树的类型
	switch (tgt.treeMode)
	{
	default:
		break;
	case tgt.PRE://先序线索二叉树
		break;
	case tgt.IN://中序线索二叉树
		//找到最左结点
		srch = tgt.threadTree->lchild;
		while (srch->ltag == tgt.LINK) srch = srch->lchild;
		//一步一步向右跑
		while (srch != tgt.threadTree) {
			out << srch->data << " ";
			if (srch->rtag == tgt.THREAD) srch = srch->rchild;
			else {
				srch = srch->rchild;
				while (srch->ltag == tgt.LINK) srch = srch->lchild;
			}
		}
		break;
	case tgt.POST://后序线索二叉树
		break;
	}
	return out;
}