/*
	Noble Team

	Asbun, Guido
	Derderian, Harry
	Kaboli, Seena
	Kim, Yeomyung
	Noble, Trevor

	December 16, 2021

	CS A250
	Project 2
*/

#include "DonorList.h"
#include "DonorType.h"

#include <set>
#include <algorithm>

using namespace std;

void DonorList::addDonor(const string& firstName,
	const string& lastName, int memberNum, double donation)
{
	donorList->insert(DonorType(firstName,lastName,
			memberNum,donation));
}

int DonorList::getNoOfDonors() const
{
	return static_cast<int>(donorList->size());
}

double DonorList::getTotalDonations() const
{
	double amountDonated = 0.0;
	for (auto const &elem : *donorList)
		amountDonated += elem.getAmountDonated();
	return amountDonated;
}

double DonorList::getHighestDonation() const
{
	double highestAmountDonated = 0.0;
	for (auto const &elem : *donorList)
	{
		double donation = elem.getAmountDonated();
		if(donation > highestAmountDonated)
			highestAmountDonated = donation;
	}
	return highestAmountDonated;
}

bool DonorList::isEmpty() const
{
	return getNoOfDonors() == 0;
}

bool DonorList::searchID(int memberID) const
{
	return find(donorList->begin(), donorList->end(), memberID) != 
			donorList->end();
}

void DonorList::deleteDonor(int memberID)
{
		auto donor = find(donorList->begin(),
					donorList->end(), memberID);
        if(donor != donorList->end())
		    donorList->erase(donor);
}

void DonorList::printAllDonors() const
{
		for (auto const &elem : *donorList)
			elem.printMemberInfo();
}

void DonorList::printAllDonations() const
{
		for (auto const &elem : *donorList)
			elem.printDonation();
}

void DonorList::clearList()
{
	donorList->clear();
}

DonorList::~DonorList()
{
	delete donorList;
	donorList = nullptr;
}
