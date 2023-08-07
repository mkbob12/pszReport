#include "pch.h"

int main()
{
	LPCTSTR pszReportJson = TEXT("F:/GIT/pszReport/report.json"); // ���� ��ο� �°� ����1
	LPCTSTR pszReportXml = TEXT("F:/GIT/pszReport/report.xml"); // ���� ��ο� �°� ����2
	LPCTSTR pszTargetXml = TEXT("F:/GIT/pszReport/target.xml"); // ���� ��ο� �°� ����3
	try
	{
		ST_REPORT report;
		if (!UTF8::ReadJsonFromFile(&report, pszReportJson))
			throw exception_format(TEXT("Reading %s failure"), pszReportJson);

		if (!UTF8::WriteXmlToFile(&report, pszReportXml))
			throw exception_format(TEXT("Writing %s failure"), pszReportXml);

		std::tstring strMyXml;
		if (EC_SUCCESS != ReadFileContents(pszReportXml, strMyXml))
			throw exception_format(TEXT("Reading MyXml %s failure"), pszReportXml);

		std::tstring strTargetXml;
		if (EC_SUCCESS != ReadFileContents(pszTargetXml, strTargetXml))
			throw exception_format(TEXT("Reading TargetXml %s failure"), pszTargetXml);
		if (strMyXml != strTargetXml)
			throw exception_format(TEXT("Not exactly matched!"));
		printf("You are succeeded!\n");
	}
	catch (const std::exception& e)
	{
		printf("%s\n", e.what());
		return -1;
	}
	return 0;
}


