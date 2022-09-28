// File: studentImp.cpp
// Description: student class definition

#include "student.h"

const double student::MAX_CHARGES = 10000.0;
const double student::MAX_GPA = 4.0;
const string student::mCodes[] = {
		"AAD - Architecture Design", 
		"AAE - Architecture", 
		"AAI - Interior Design", 
		"AAL - Landscape Architecture", 
		"AAP - Urban Planning", 
		"AAS - Afro-American Studies", 
		"ABS - Architecture Building Science", 
		"ACA - Architecture Construction Mgmt", 
		"ACC - Accounting", 
		"AES - Aerospace Studies", 
		"AHP - Allied Health", 
		"AIS - Asian Studies", 
		"ANT - Anthropology", 
		"ANTH - Anthropology", 
		"ARA - Arabic", 
		"ART - Art", 
		"AST - Astronomy", 
		"ATE - Athletic Training", 
		"BGES - Business Global Entrepeneurial", 
		"BIO - Biological Sciences", 
		"BLW - Business Law", 
		"BUS - Business Administration", 
		"CED - Counselor Education", 
		"CEE - Civil Engineering", 
		"CEG - Civil Engineering", 
		"CEM - Construction Management", 
		"CEP - Counseling & Educ Psych", 
		"CFA - College of Fine Arts", 
		"CHE - Chemistry", 
		"CHI - Chinese", 
		"CIE - Curric & Instruct: Elementary", 
		"CIG - Curric & Instruct: General", 
		"CIL - Curric & Instruct: Literacy", 
		"CIM - Curric & Instruct: Media", 
		"CIR - Curric & Instruct: Read", 
		"CIS - Curric & Instruct: Secondary", 
		"CIT - Curric & Instruct: Technology", 
		"CITR - Curric & Instruct: Tech RPDP", 
		"CLA - Classical Studies", 
		"CLS - Clinical Laboratory Science", 
		"CMI - Comprehensive Medical Imaging", 
		"CNS - Consciousness Studies", 
		"COE - College of Education", 
		"COL - Comparative Literature", 
		"COLA - College of Liberal Arts", 
		"COM - Communication Studies", 
		"COS - Communication Studies", 
		"COU - Counseling", 
		"CPE - Computer Engineering", 
		"CPS - Counseling", 
		"CRJ - Criminal Justice", 
		"CS - Computer Science", 
		"CSC - Computer Science", 
		"CST - Cultural Studies", 
		"DAN - Dance", 
		"DEN - Dentistry", 
		"DES - Design", 
		"DMS - Diagnostic Medial Sonography", 
		"DPT - Physical Therapy", 
		"EAB - Bio Methods", 
		"ECD - Educ Career & Personal Devel", 
		"ECE - Early Childhood", 
		"ECEM - Emergency Management", 
		"ECG - Electrical And Computer Engine", 
		"ECH - Early Childhood", 
		"ECO - Economics", 
		"ECON - Economics", 
		"EDA - Educational Administration", 
		"EDCT - Career Education", 
		"EDEL - Education: Elementary", 
		"EDH - Educational Leadership Phd", 
		"EDMS - Education: Middle School", 
		"EDRL - Education: Reading & Language", 
		"EDSC - Education: Secondary", 
		"EDSP - Special Education", 
		"EDU - Education", 
		"EDUC - Education: Upper Division", 
		"EDW - Workforce Education", 
		"EDWF - Workforce Education", 
		"EE - Electrical And Computer Engine", 
		"EED - Entertainment Engineering", 
		"EEG - Electrical Engineering", 
		"EGG - Engineering", 
		"EMBA - Executive Masters", 
		"ENG - English", 
		"ENGL - English", 
		"ENS - Environmental Science", 
		"ENV - Environmental Studies", 
		"EOH - Env/Occ Health", 
		"EPC - Educational Psychology", 
		"EPP - Educational Psychology", 
		"EPS - Ethics And Policy Studies", 
		"EPY - Educational Psychology", 
		"ESE - Secondary Education", 
		"ESL - English As A Second Language", 
		"ESP - Special Education", 
		"ESR - Secondary Education Reading", 
		"ETS - Ethnic Studies", 
		"EXL - Excell Pgrm", 
		"FAB - Food & Beverage", 
		"FIN - Finance", 
		"FIS - Film", 
		"FOL - Foreign Language", 
		"FRE - French", 
		"FREN - French", 
		"GAM - Gaming Management", 
		"GEOG - Geography", 
		"GEOL - Geology", 
		"GER - German", 
		"GRA - Graduate College", 
		"GRE - Greek", 
		"GSC - General Studies Communication", 
		"GWK - Great Works Certificate", 
		"HCA - Health Care Administration", 
		"HEB - Hebrew", 
		"HED - Health Education", 
		"HIS - History", 
		"HIST - History", 
		"HMD - Hotel Management", 
		"HOA - Hotel Administration", 
		"HON - Honors", 
		"HPS - Health Physics", 
		"HSC - Health Science", 
		"IB - International Business", 
		"ICE - Curric & Instruct: Elementary", 
		"ICG - Curric & Instruct: Genereral", 
		"ICS - Instruction & Curricular Stud", 
		"IDS - Interdisciplinary Studies", 
		"INF - Informatics", 
		"IPG - International Programs", 
		"IS - Management Information Systems", 
		"ITA - Italian", 
		"ITAL - Italian", 
		"JAP - Japanese", 
		"JMS - Journalism & Media Studies", 
		"JOUR - Journalism & Media Studies", 
		"JPN - Japanese", 
		"KIN - Kinesiology", 
		"LAND - Landscape Architecture", 
		"LAS - Latin American Studies", 
		"LAT - Latin", 
		"LAW - Law", 
		"LBS - Liberal Studies", 
		"LIB - Library Science", 
		"LIN - Linguistics", 
		"MAT - Mathematics", 
		"MATH - Mathematics", 
		"MBA - Master Business Administration", 
		"ME - Mechanical Engineering", 
		"MEG - Mechanical Engineering", 
		"MFT - Marriage & Family Therapy", 
		"MGT - Management", 
		"MIL - Military Science", 
		"MIS - Management Information Systems", 
		"MKT - Marketing", 
		"MSC - Military Science", 
		"MSFS - Multidisc: Forensic Science", 
		"MUS - Music", 
		"MUSA - Music", 
		"MUSC - Music", 
		"MUSE - Music", 
		"NRES - Environmental Studies", 
		"NSE - National Student Exchange", 
		"NTR - Nutrition Sciences", 
		"NUC - Nuclear Medicine", 
		"NUE - Nuclear Engineering", 
		"NUR - Nursing", 
		"NURS - Nursing", 
		"NUTR - Nutrition Sciences", 
		"ORTH - Orthodontics", 
		"PAF - Public Affairs", 
		"PBH - Public Health", 
		"PED - Physical Education", 
		"PEDO - Pediatric Dentistry", 
		"PER - Persian", 
		"PEX - Physical Education: Activity", 
		"PGDE - Postgraduate Dental Education", 
		"PGM - PGA Golf Management", 
		"PHI - Philosophy", 
		"PHIL - Philosophy", 
		"PHS - Physical Sciences", 
		"PHT - Physical Therapy", 
		"PHY - Physics", 
		"PHYS - Physics", 
		"PORT - Portuguese", 
		"POS - Political Science", 
		"PSY - Psychology", 
		"PTG - Portuguese", 
		"PTS - Physical Therapy Science", 
		"PUA - Public Administration", 
		"RAD - Radiologic Technology", 
		"RDCH - Radiochemistry", 
		"RE - Real Estate", 
		"REC - Recreation",
		"REG - Religious Studies", 
		"RLS - Recreation & Sport Management", 
		"RPDP - Reg Professional Development", 
		"RSC - Radiological Sciences", 
		"RUS - Russian", 
		"SCI - Science", 
		"SCM - Supply Chain", 
		"SIM - Sports Injury Management", 
		"SLS - Sport & Leisure Studies", 
		"SOC - Sociology", 
		"SPA - Spanish", 
		"SPAN - Spanish", 
		"STA - Statistics", 
		"STAT - Statistics", 
		"SW - Social Work", 
		"SWK - Social Work", 
		"TCA - Tourism", 
		"TESL - English as a Second Language", 
		"THA - Theatre Arts", 
		"THTR - Theatre Arts", 
		"TRCR - Transferred Elective Credit",
		"ULD - Urban Leadership", 
		"UNS - University Studies", 
		"WDL - Workforce Development", 
		"WMST - Women's Studies", 
		"WOM - Women's Studies",
		"WRM - Water Resources Management",
		"UND - Undeclared" };

student::student(string last, string first, string id, string majorCode,
	double gradePtAvg, double charge, double aid)
{
	string temp;
	lastName = last;
	firstName = first;

	if (id != "")
	{
		if (!checkID(id))
		{
			cout << "Error, invalid student ID." << endl;
			studentID = "";
		}
		else
			studentID = id;
	}
	else
		studentID = id;

	if (majorCode != "")
	{
		temp = expandMajorCode(majorCode);
		if (temp == "Error")
		{
			cout << "Error, invalid student major." << endl;
			major = "";
		}
		else
			major = temp;
	}
	else
		major = "Error";

	if (gradePtAvg < 0.0 || gradePtAvg > MAX_GPA)
	{
		cout << "Error, invalid GPA." << endl;
		gpa = 0.0;
	}
	else
		gpa = gradePtAvg;

	if (charge < 0.0 || charge > MAX_CHARGES)
	{
		cout << "Error, invalid charges amount." << endl;
		charges = 0.0;
	}
	else
		charges = charge;

	if (aid < 0.0 || aid > charge)
	{
		cout << "Error, invalid financial aid amount." << endl;
		financialAid = 0.0;
	}
	else
		financialAid = aid;

	balance = abs(financialAid - charges);
}

string student::getLastName() const
{
	return lastName;
}

string student::getFirstName() const
{
	return firstName;
}

string student::getID() const
{
	return studentID;
}

void student::getCharges(double &charge, double &aid) const
{
	charge = charges;
	aid = financialAid;
}

double student::getBalance() const
{
	return balance;
}

string student::getMajor() const
{
	return major;
}

double student::getGPA() const
{
	return gpa;
}

void student::setName(string last, string first)
{
	lastName = last;
	firstName = first;
}

void student::setID(string id)
{
	if (!checkID(id))
		cout << "Error, invalid student ID." << endl;
	else
		studentID = id;
}

void student::setMajor(string majorCode)
{
	string temp = expandMajorCode(majorCode);

	if (temp == "Error") // If error, we would leave major unaltered.
		cout << "Error, invalid student major." << endl;
	else // No error, so we change.
		major = temp;
}

void student::setCharges(double charge, double aid)
{
	if (charge < 0.0 || charge > MAX_CHARGES)
		cout << "Error, invalid charges amount." << endl;
	else
		charges = charge;

	if (aid < 0.0 || aid > charge)
		cout << "Error, invalid financial aid amount." << endl;
	else
		financialAid = aid;

	balance = abs(financialAid - charges);
}

void student::setGPA(double gradePtAvg)
{
	if (gradePtAvg < 0.0 || gradePtAvg > MAX_GPA)
		cout << "Error, invalid GPA." << endl;
	else
		gpa = gradePtAvg;
}

void student::showStudent()
{
	string	bars;
	bars.append(70,'-');
	streamsize ssize = cout.precision(2); // Save and set new precision.

	cout << fixed << showpoint;

	cout << endl << bars << endl;

	cout << "Student Summary\n";
	cout << setw(14) << "Name: " << lastName << ", " << firstName << endl;
	cout << setw(14) << "ID: " << studentID << endl;
	cout << setw(14) << "Major: " << major << endl;
	cout << setw(14) << "GPA: " << setw(8) << gpa << endl;
	cout << setw(14) << "Charges: " << setw(8) << charges;
	cout << setw(30) << "Financial Aid: " << setw(8) << financialAid << endl;
	cout << setw(14) << "Balance: " << setw(8) << balance
		 << endl << endl;

	// Reset flags.
	cout.unsetf(ios::fixed | ios::showpoint);
	cout << setprecision(ssize);
}

bool student::checkID(string id) const
{
	// Must have ten characters (L and 9 digits).
	if (id.size() != 10)
		return false;

	// First character must be an L.
	if (id[0] != 'L')
		return false;

	// Return false if following characters not digits.
	for (size_t i = 1; i < id.size(); i++)
	{
		if (id[i] < '0' || id[i] > '9')
			return false;
	}

	return true;
}

string student::expandMajorCode(string majorCode)
{
	size_t majorCodeLen = majorCode.size();

	if (majorCodeLen < 2)
		return "Error";

	for (size_t i = 0; i < sizeof(mCodes) / sizeof(string); i++)
	{
		// Compare the n characters of mCode with the majorCode,
		// where n is the length of majorCOde.
		if (mCodes[i].substr(0, majorCodeLen) == majorCode)
			return mCodes[i]; // Match found.
	}
	
	return "Error";
}