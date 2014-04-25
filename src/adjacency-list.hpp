#ifndef NLSR_ADL_HPP
#define NLSR_ADL_HPP

#include <ndn-cxx/common.hpp>
#include <list>

#include "adjacent.hpp"

namespace nlsr {
class Nlsr;

class AdjacencyList
{

public:
  AdjacencyList();
  ~AdjacencyList();

  int
  insert(Adjacent& adj);

  int
  updateAdjacentStatus(const std::string& adjName, int s);

  int
  updateAdjacentLinkCost(const std::string& adjName, double lc);

  std::list<Adjacent>&
  getAdjList();

  bool
  isNeighbor(const std::string& adjName);

  void
  incrementTimedOutInterestCount(const std::string& neighbor);

  int
  getTimedOutInterestCount(const std::string& neighbor);

  int
  getStatusOfNeighbor(const std::string& neighbor);

  void
  setStatusOfNeighbor(const std::string& neighbor, int status);

  void
  setTimedOutInterestCount(const std::string& neighbor, int count);

  void
  addAdjacentsFromAdl(AdjacencyList& adl);

  bool
  isAdjLsaBuildable(Nlsr& pnlsr);

  int
  getNumOfActiveNeighbor();

  Adjacent
  getAdjacent(const std::string& adjName);

  bool
  isEqual(AdjacencyList& adl);

  int
  getSize()
  {
    return m_adjList.size();
  }

  void
  reset()
  {
    if (m_adjList.size() > 0)
    {
      m_adjList.clear();
    }
  }

  void
  print();

private:
  std::list<Adjacent>::iterator
  find(std::string adjName);

private:
  std::list<Adjacent> m_adjList;
};

} //namespace nlsr
#endif //NLSR_ADL_HPP