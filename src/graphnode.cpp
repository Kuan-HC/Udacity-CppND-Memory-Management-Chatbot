#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////
    /* Task 0*/
    /* _chatBot was not created in GraphNode */
    //delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
/********************************************************
 * reference
 * https://knowledge.udacity.com/questions/117912
 ********************************************************/
void GraphNode::MoveChatbotHere(ChatBot &&chatbot)
{
    _chatBot = std::move(chatbot);
    std::cout << "Task 5.4 call SetCurrentNode" <<std::endl;
    _chatBot.SetCurrentNode(this);
    std::cout << "Task 5.5 SetCurrentNode End" <<std::endl;
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    std::cout << "Task 5 MoveChatbotToNewNode" <<std::endl; /* for debug */
    newNode->MoveChatbotHere(std::move(_chatBot));
    //_chatBot = nullptr; // invalidate pointer at source
    std::cout << "Task 5 MoveChatbotToNewNode End" <<std::endl; /* for debug */
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}