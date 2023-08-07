#pragma once
#include <vector>
#include <string>

struct ST_SUMMARY: public core::IFormatterObject
{
	std::tstring strResult;
	std::tstring strDetectName;
	std::tstring strEngineName;
	std::tstring strEngineVersion;
	std::tstring strSeverity;
	std::tstring strSampleName;
	std::tstring strSampleExt;
	std::tstring CurLoopCount;
	std::tstring MaxLoopCount;
	std::tstring TotalElapsedTime;
	


	void OnSync(core::IFormatter& formatter)
	{
		formatter
			+ core::sPair(TEXT("Result"), strResult)
			+ core::sPair(TEXT("DetectName"), strDetectName)
			+ core::sPair(TEXT("EngineName"), strEngineName)
			+ core::sPair(TEXT("EngineVersion"), strEngineVersion)
			+ core::sPair(TEXT("Severity"), strResult)
			+ core::sPair(TEXT("DetectName"), strDetectName)
			+ core::sPair(TEXT("EngineName"), strEngineName)
			+ core::sPair(TEXT("EngineVersion"), strEngineVersion)
			+ core::sPair(TEXT("Severity"), strSeverity)
			+ core::sPair(TEXT("SampleName"), strSampleName)
			+ core::sPair(TEXT("SampleExt"), strSampleExt)
			;
	}
};


struct ST_TARGET : public core::IFormatterObject
{
	std::tstring strTargetID;
	std::tstring strParentID;
	std::tstring strAbsolutePath;
	std::tstring strFileName;
	std::tstring strFileSize;
	std::tstring strFileEXT;
	std::tstring strMD5;
	std::tstring strSHA1;
	std::tstring strSHA256;
	std::tstring strHAS160;
	std::tstring strFileHeaderDump;
	std::tstring strIsExtractedFile;



	void OnSync(core::IFormatter& formatter)
	{
		formatter
			+ core::sPair(TEXT("TargetID"), strTargetID)
			+ core::sPair(TEXT("ParentID"), strParentID)
			+ core::sPair(TEXT("AbsolutePath"), strAbsolutePath)
			+ core::sPair(TEXT("FileName"), strFileName)
			+ core::sPair(TEXT("FileSIze"), strFileSize)
			+ core::sPair(TEXT("FileEXT"), strFileEXT)
			+ core::sPair(TEXT("MD5"), strMD5)
			+ core::sPair(TEXT("SHA1"), strSHA1)
			+ core::sPair(TEXT("SHA256"), strSHA256)
			+ core::sPair(TEXT("HAS160"), strHAS160)
			+ core::sPair(TEXT("FileHeaderDump"), strFileHeaderDump)
			+ core::sPair(TEXT("IsExtractedFile"), strIsExtractedFile)
			;
	}
};

struct ST_TargetFile : public core::IFormatterObject {

	ST_TARGET Target;


	void OnSync(core::IFormatter& formatter)
	{
		formatter
			+ core::sPair(TEXT("1777336a2b446fbca3172d309884ee65e4e6c0655b3ce1a38301a9c6d61f7195.vbs"), Target);
		;
	}

};




struct ST_TARGETS : public core::IFormatterObject {

	ST_TargetFile TargetFile;


	void OnSync(core::IFormatter& formatter)
	{
		formatter
			+ core::sPair(TEXT("TargetFile"), TargetFile);
		;
	}

};

struct ST_FIRST : public core::IFormatterObject {


	std::tstring strEngineName;
	std::tstring strEngineVersion;
	std::tstring strTargetID;
	std::tstring strPlatformID;
	std::tstring strName;
	std::tstring strAnalysisCode;
	std::tstring strSeverity;
	std::tstring strDesc; 


	void OnSync(core::IFormatter& formatter)
	{
		formatter
			+ core::sPair(TEXT("EngineName"), strEngineName)
			+ core::sPair(TEXT("EngineVersion"), strEngineVersion)
			+ core::sPair(TEXT("TargetID"), strTargetID)
			+ core::sPair(TEXT("PlatformID"), strPlatformID)
			+ core::sPair(TEXT("Name"), strName)
			+ core::sPair(TEXT("AnalysisCode"), strAnalysisCode)
			+ core::sPair(TEXT("EngineName"), strEngineName)
			+ core::sPair(TEXT("Severity"), strEngineVersion)
			+ core::sPair(TEXT("Severity"), strSeverity)
			+ core::sPair(TEXT("Desc"), strDesc)

		;
	}

};




struct ST_DETECTION : public core::IFormatterObject {

	ST_FIRST First;
	
	std::vector<core::IFormatterObject*> objects;



	void OnSync(core::IFormatter& formatter)
	{

		objects.push_back(&First);
		objects.push_back(&First);
		objects.push_back(&First);
		objects.push_back(&First);
		objects.push_back(&First);
		objects.push_back(&First);

		formatter
			+ core::sPair(TEXT("Event"), objects)
			;


	}

};

struct ST_REPORT : public core::IFormatterObject
{
	ST_SUMMARY Summary;
	ST_TARGETS Targets; 
	ST_DETECTION Detection;

	
	

	void OnSync(core::IFormatter& formatter)
	{
		formatter
			+ core::sPair(TEXT("Summary"), Summary)
			+ core::sPair(TEXT("Targets"), Targets)
			+ core::sPair(TEXT("Detection"), Detection)
	
			;
	}
};

