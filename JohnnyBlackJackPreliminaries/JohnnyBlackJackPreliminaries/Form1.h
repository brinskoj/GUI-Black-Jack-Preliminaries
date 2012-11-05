/******************************************************************************
*******************************************************************************
*******************************************************************************
***																			***
***						ID INFORMATION										***
***                                                        					***
***   Programmers				:			Johnny Brinsko		 			***
***   Assignment #				:   		TA #2.BJ			   			***
***   Assignment Name			:			GUI BlackJack Preliminaries		***
***   Course # and Title		:	   		CISC 192 - C++					***
***   Class Meeting Time		:	   		TTh 9:35 - 12:40				***
***   Instructor				:			Professor Forman				***
***   Hours						:			9								***
***   Difficulty				:			4								***
***   Completion Date			:			10/30/2012						***
***   Project Name				:  			JohnnyBlackJackPreliminaries	***	 
***																			***
*******************************************************************************
*******************************************************************************
***                                       							***
***						PROGRAM DESCRIPTION              			***
***																	***
***	 Has user select one card from the left side and one card from	***
***	 the right side. If user tries to select a card from the same	***
***	 side as the card previously, user will get a message saying	***
***	 to choose a card from the other side. If the user selects an	***
***	 Ace, user will be asked to give the value a 1 or 11. Shows		***
***	 the selected card from each side in a separate picture box.	***
***	 After both cards are selected, adds the card values and		***
***	 determines if user should hit or stay. If user has blackjack	***
***	 by getting a sum of 21 or busts by going over 21 the user will	***
***	 be informed through a label. User can reset all values by		***
***	 clicking the "Play On" button. When user exits, music is		***
***	 played, shows the stats of the game, and finally the ID Info	***
***	 and stars earned.												***
***                                                         		***
***********************************************************************
***********************************************************************
***																	***
***					Event-Defined Function List						***
***                                                         		***
***		buttonDateTime_Click										***
***		buttonElapsedTime_Click										***
***		buttonExit_Click											***
***		pictureBoxAceL_Click										***
***		pictureBoxFiveL_Click										***
***		pictureBoxJackL_Click										***
***		pictureBoxAceR_Click										***
***		pictureBox5R_Click											***
***		pictureBoxJackR_Click										***
***		buttonPlayOn_Click											***
***		timerElapsedTime_Tick										***
***																	***
***********************************************************************
***********************************************************************
***																	***
***					Custom-Defined Function List					***
***                                                         		***
***		displayDateTime												***
***		farewell													***
***		observeCards												***
***		selectCard													***
***																	***
***********************************************************************
***********************************************************************
***																	***
***                         CREDITS				                    ***
***                                                         		***
***   		Thanks for assistance and inspiration from:        		***
***                                                         		***
***				   Professor Forman and Tim							***
***                                                         		***
***   		Thanks for the opportunity to assist and inspire:     	***
***								                               		***
***				   Professor Forman and Tim							***
***                                                         		***
***********************************************************************
***********************************************************************
***																	***
***						      MEDIA				                    ***
***																	***
***		Farewell music:												***
***	http://www.gamefront.com/files/12899141/Portal_Radio_Loop		***
***																	***
***		Jose's cards from class, provided by Professor Forman		***
***																	***
***		Animated gif of blackjack dealing							***
***			(used gifsoup.com to convert video to gif)				***
***	http://www.youtube.com/watch?v=V6WQrbauJEQ						***
***																	***
***********************************************************************
***********************************************************************
**********************************************************************/

#pragma once

namespace JohnnyBlackJackPreliminaries {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;		// For play sound!!

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			dateTimeStart = DateTime::Now;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  labelWelcome;
	protected: 
	private: System::Windows::Forms::Label^  labelDateTime;
	private: System::Windows::Forms::Button^  buttonDateTime;
	private: System::Windows::Forms::Button^  buttonExit;
	private: System::Windows::Forms::Button^  buttonPlayOn;
	private: System::Windows::Forms::Label^  labelInstructions;
	private: System::Windows::Forms::PictureBox^  pictureBoxFiveL;
	private: System::Windows::Forms::PictureBox^  pictureBoxJackL;
	private: System::Windows::Forms::PictureBox^  pictureBoxAceL;
	private: System::Windows::Forms::PictureBox^  pictureBoxAceR;
	private: System::Windows::Forms::PictureBox^  pictureBoxJackR;
	private: System::Windows::Forms::PictureBox^  pictureBox5R;
	private: System::Windows::Forms::Label^  labelFirstCard;
	private: System::Windows::Forms::Label^  labelSecondCard;
	private: System::Windows::Forms::Label^  labelFirstCardName;
	private: System::Windows::Forms::Label^  labelSecondCardName;
	private: System::Windows::Forms::Label^  labelFirstCardValue;
	private: System::Windows::Forms::Label^  labelSecondCardValue;
	private: System::Windows::Forms::Label^  labelHorizontalRule;
	private: System::Windows::Forms::Label^  labelSumName;
	private: System::Windows::Forms::Label^  labelSumValue;
	private: System::Windows::Forms::Label^  labelObservation;
	private: System::Windows::Forms::PictureBox^  pictureBoxSelectedCardLeft;
	private: System::Windows::Forms::PictureBox^  pictureBoxSelectedCardRight;
	private: System::Windows::Forms::PictureBox^  pictureBoxBJGif;
	private: System::Windows::Forms::Button^  buttonElapsedTime;
	private: System::Windows::Forms::Label^  labelElapsedTime;
	private: System::Windows::Forms::Timer^  timerElapsedTime;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->labelWelcome = (gcnew System::Windows::Forms::Label());
			this->labelDateTime = (gcnew System::Windows::Forms::Label());
			this->buttonDateTime = (gcnew System::Windows::Forms::Button());
			this->buttonExit = (gcnew System::Windows::Forms::Button());
			this->buttonPlayOn = (gcnew System::Windows::Forms::Button());
			this->labelInstructions = (gcnew System::Windows::Forms::Label());
			this->pictureBoxFiveL = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxJackL = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxAceL = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxAceR = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxJackR = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5R = (gcnew System::Windows::Forms::PictureBox());
			this->labelFirstCard = (gcnew System::Windows::Forms::Label());
			this->labelSecondCard = (gcnew System::Windows::Forms::Label());
			this->labelFirstCardName = (gcnew System::Windows::Forms::Label());
			this->labelSecondCardName = (gcnew System::Windows::Forms::Label());
			this->labelFirstCardValue = (gcnew System::Windows::Forms::Label());
			this->labelSecondCardValue = (gcnew System::Windows::Forms::Label());
			this->labelHorizontalRule = (gcnew System::Windows::Forms::Label());
			this->labelSumName = (gcnew System::Windows::Forms::Label());
			this->labelSumValue = (gcnew System::Windows::Forms::Label());
			this->labelObservation = (gcnew System::Windows::Forms::Label());
			this->pictureBoxSelectedCardLeft = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxSelectedCardRight = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxBJGif = (gcnew System::Windows::Forms::PictureBox());
			this->buttonElapsedTime = (gcnew System::Windows::Forms::Button());
			this->labelElapsedTime = (gcnew System::Windows::Forms::Label());
			this->timerElapsedTime = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxFiveL))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxJackL))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxAceL))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxAceR))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxJackR))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5R))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxSelectedCardLeft))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxSelectedCardRight))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxBJGif))->BeginInit();
			this->SuspendLayout();
			// 
			// labelWelcome
			// 
			this->labelWelcome->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->labelWelcome->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelWelcome->Location = System::Drawing::Point(404, 25);
			this->labelWelcome->Name = L"labelWelcome";
			this->labelWelcome->Size = System::Drawing::Size(483, 165);
			this->labelWelcome->TabIndex = 0;
			this->labelWelcome->Text = L"Welcome Friends and Neighbors to Johnny\'s Black Jack Room";
			this->labelWelcome->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelDateTime
			// 
			this->labelDateTime->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->labelDateTime->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelDateTime->Location = System::Drawing::Point(957, 25);
			this->labelDateTime->Name = L"labelDateTime";
			this->labelDateTime->Size = System::Drawing::Size(295, 63);
			this->labelDateTime->TabIndex = 1;
			this->labelDateTime->Text = L"Thursday, January 01, 1970 12:00:00 AM";
			this->labelDateTime->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// buttonDateTime
			// 
			this->buttonDateTime->FlatAppearance->BorderColor = System::Drawing::Color::YellowGreen;
			this->buttonDateTime->FlatAppearance->BorderSize = 4;
			this->buttonDateTime->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Yellow;
			this->buttonDateTime->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->buttonDateTime->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonDateTime->Location = System::Drawing::Point(1051, 91);
			this->buttonDateTime->Name = L"buttonDateTime";
			this->buttonDateTime->Size = System::Drawing::Size(138, 38);
			this->buttonDateTime->TabIndex = 2;
			this->buttonDateTime->Text = L"Update Date / Time";
			this->buttonDateTime->UseVisualStyleBackColor = true;
			this->buttonDateTime->Click += gcnew System::EventHandler(this, &Form1::buttonDateTime_Click);
			// 
			// buttonExit
			// 
			this->buttonExit->FlatAppearance->BorderColor = System::Drawing::Color::YellowGreen;
			this->buttonExit->FlatAppearance->BorderSize = 4;
			this->buttonExit->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Yellow;
			this->buttonExit->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->buttonExit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonExit->Location = System::Drawing::Point(1141, 512);
			this->buttonExit->Name = L"buttonExit";
			this->buttonExit->Size = System::Drawing::Size(111, 38);
			this->buttonExit->TabIndex = 3;
			this->buttonExit->Text = L"Exit";
			this->buttonExit->UseVisualStyleBackColor = true;
			this->buttonExit->Click += gcnew System::EventHandler(this, &Form1::buttonExit_Click);
			// 
			// buttonPlayOn
			// 
			this->buttonPlayOn->FlatAppearance->BorderColor = System::Drawing::Color::YellowGreen;
			this->buttonPlayOn->FlatAppearance->BorderSize = 4;
			this->buttonPlayOn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Yellow;
			this->buttonPlayOn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->buttonPlayOn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonPlayOn->Location = System::Drawing::Point(12, 512);
			this->buttonPlayOn->Name = L"buttonPlayOn";
			this->buttonPlayOn->Size = System::Drawing::Size(111, 38);
			this->buttonPlayOn->TabIndex = 4;
			this->buttonPlayOn->Text = L"Play On";
			this->buttonPlayOn->UseVisualStyleBackColor = true;
			this->buttonPlayOn->Click += gcnew System::EventHandler(this, &Form1::buttonPlayOn_Click);
			// 
			// labelInstructions
			// 
			this->labelInstructions->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelInstructions->Location = System::Drawing::Point(310, 204);
			this->labelInstructions->Name = L"labelInstructions";
			this->labelInstructions->Size = System::Drawing::Size(658, 57);
			this->labelInstructions->TabIndex = 5;
			this->labelInstructions->Text = L"Instructions: Click on one card from each column";
			this->labelInstructions->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBoxFiveL
			// 
			this->pictureBoxFiveL->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBoxFiveL.Image")));
			this->pictureBoxFiveL->Location = System::Drawing::Point(129, 297);
			this->pictureBoxFiveL->Name = L"pictureBoxFiveL";
			this->pictureBoxFiveL->Size = System::Drawing::Size(73, 97);
			this->pictureBoxFiveL->TabIndex = 6;
			this->pictureBoxFiveL->TabStop = false;
			this->pictureBoxFiveL->Click += gcnew System::EventHandler(this, &Form1::pictureBoxFiveL_Click);
			// 
			// pictureBoxJackL
			// 
			this->pictureBoxJackL->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBoxJackL.Image")));
			this->pictureBoxJackL->Location = System::Drawing::Point(85, 351);
			this->pictureBoxJackL->Name = L"pictureBoxJackL";
			this->pictureBoxJackL->Size = System::Drawing::Size(73, 97);
			this->pictureBoxJackL->TabIndex = 7;
			this->pictureBoxJackL->TabStop = false;
			this->pictureBoxJackL->Click += gcnew System::EventHandler(this, &Form1::pictureBoxJackL_Click);
			// 
			// pictureBoxAceL
			// 
			this->pictureBoxAceL->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBoxAceL.Image")));
			this->pictureBoxAceL->Location = System::Drawing::Point(50, 400);
			this->pictureBoxAceL->Name = L"pictureBoxAceL";
			this->pictureBoxAceL->Size = System::Drawing::Size(73, 97);
			this->pictureBoxAceL->TabIndex = 8;
			this->pictureBoxAceL->TabStop = false;
			this->pictureBoxAceL->Click += gcnew System::EventHandler(this, &Form1::pictureBoxAceL_Click);
			// 
			// pictureBoxAceR
			// 
			this->pictureBoxAceR->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBoxAceR.Image")));
			this->pictureBoxAceR->Location = System::Drawing::Point(1141, 400);
			this->pictureBoxAceR->Name = L"pictureBoxAceR";
			this->pictureBoxAceR->Size = System::Drawing::Size(73, 97);
			this->pictureBoxAceR->TabIndex = 11;
			this->pictureBoxAceR->TabStop = false;
			this->pictureBoxAceR->Click += gcnew System::EventHandler(this, &Form1::pictureBoxAceR_Click);
			// 
			// pictureBoxJackR
			// 
			this->pictureBoxJackR->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBoxJackR.Image")));
			this->pictureBoxJackR->Location = System::Drawing::Point(1104, 351);
			this->pictureBoxJackR->Name = L"pictureBoxJackR";
			this->pictureBoxJackR->Size = System::Drawing::Size(73, 97);
			this->pictureBoxJackR->TabIndex = 10;
			this->pictureBoxJackR->TabStop = false;
			this->pictureBoxJackR->Click += gcnew System::EventHandler(this, &Form1::pictureBoxJackR_Click);
			// 
			// pictureBox5R
			// 
			this->pictureBox5R->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox5R.Image")));
			this->pictureBox5R->Location = System::Drawing::Point(1068, 297);
			this->pictureBox5R->Name = L"pictureBox5R";
			this->pictureBox5R->Size = System::Drawing::Size(73, 97);
			this->pictureBox5R->TabIndex = 9;
			this->pictureBox5R->TabStop = false;
			this->pictureBox5R->Click += gcnew System::EventHandler(this, &Form1::pictureBox5R_Click);
			// 
			// labelFirstCard
			// 
			this->labelFirstCard->AutoSize = true;
			this->labelFirstCard->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelFirstCard->Location = System::Drawing::Point(400, 297);
			this->labelFirstCard->Name = L"labelFirstCard";
			this->labelFirstCard->Size = System::Drawing::Size(169, 24);
			this->labelFirstCard->TabIndex = 12;
			this->labelFirstCard->Text = L"First Card Selected";
			// 
			// labelSecondCard
			// 
			this->labelSecondCard->AutoSize = true;
			this->labelSecondCard->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelSecondCard->Location = System::Drawing::Point(400, 321);
			this->labelSecondCard->Name = L"labelSecondCard";
			this->labelSecondCard->Size = System::Drawing::Size(200, 24);
			this->labelSecondCard->TabIndex = 13;
			this->labelSecondCard->Text = L"Second Card Selected";
			// 
			// labelFirstCardName
			// 
			this->labelFirstCardName->AutoSize = true;
			this->labelFirstCardName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelFirstCardName->Location = System::Drawing::Point(611, 297);
			this->labelFirstCardName->Name = L"labelFirstCardName";
			this->labelFirstCardName->Size = System::Drawing::Size(134, 24);
			this->labelFirstCardName->TabIndex = 14;
			this->labelFirstCardName->Text = L"1st Card Name";
			// 
			// labelSecondCardName
			// 
			this->labelSecondCardName->AutoSize = true;
			this->labelSecondCardName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelSecondCardName->Location = System::Drawing::Point(611, 321);
			this->labelSecondCardName->Name = L"labelSecondCardName";
			this->labelSecondCardName->Size = System::Drawing::Size(143, 24);
			this->labelSecondCardName->TabIndex = 15;
			this->labelSecondCardName->Text = L"2nd Card Name";
			// 
			// labelFirstCardValue
			// 
			this->labelFirstCardValue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelFirstCardValue->Location = System::Drawing::Point(852, 297);
			this->labelFirstCardValue->Name = L"labelFirstCardValue";
			this->labelFirstCardValue->Size = System::Drawing::Size(35, 24);
			this->labelFirstCardValue->TabIndex = 16;
			this->labelFirstCardValue->Text = L". . .";
			this->labelFirstCardValue->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// labelSecondCardValue
			// 
			this->labelSecondCardValue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelSecondCardValue->Location = System::Drawing::Point(852, 321);
			this->labelSecondCardValue->Name = L"labelSecondCardValue";
			this->labelSecondCardValue->Size = System::Drawing::Size(35, 24);
			this->labelSecondCardValue->TabIndex = 17;
			this->labelSecondCardValue->Text = L". . .";
			this->labelSecondCardValue->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// labelHorizontalRule
			// 
			this->labelHorizontalRule->AutoSize = true;
			this->labelHorizontalRule->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelHorizontalRule->Location = System::Drawing::Point(400, 351);
			this->labelHorizontalRule->Name = L"labelHorizontalRule";
			this->labelHorizontalRule->Size = System::Drawing::Size(494, 24);
			this->labelHorizontalRule->TabIndex = 18;
			this->labelHorizontalRule->Text = L"============================================";
			this->labelHorizontalRule->Visible = false;
			// 
			// labelSumName
			// 
			this->labelSumName->AutoSize = true;
			this->labelSumName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelSumName->Location = System::Drawing::Point(400, 384);
			this->labelSumName->Name = L"labelSumName";
			this->labelSumName->Size = System::Drawing::Size(223, 24);
			this->labelSumName->TabIndex = 19;
			this->labelSumName->Text = L"Total Sum of Card Values";
			this->labelSumName->Visible = false;
			// 
			// labelSumValue
			// 
			this->labelSumValue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelSumValue->Location = System::Drawing::Point(849, 384);
			this->labelSumValue->Name = L"labelSumValue";
			this->labelSumValue->Size = System::Drawing::Size(35, 24);
			this->labelSumValue->TabIndex = 20;
			this->labelSumValue->Text = L". . .";
			this->labelSumValue->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->labelSumValue->Visible = false;
			// 
			// labelObservation
			// 
			this->labelObservation->AutoSize = true;
			this->labelObservation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelObservation->Location = System::Drawing::Point(404, 440);
			this->labelObservation->Name = L"labelObservation";
			this->labelObservation->Size = System::Drawing::Size(111, 24);
			this->labelObservation->TabIndex = 21;
			this->labelObservation->Text = L"Observation";
			this->labelObservation->Visible = false;
			// 
			// pictureBoxSelectedCardLeft
			// 
			this->pictureBoxSelectedCardLeft->Location = System::Drawing::Point(315, 297);
			this->pictureBoxSelectedCardLeft->Name = L"pictureBoxSelectedCardLeft";
			this->pictureBoxSelectedCardLeft->Size = System::Drawing::Size(73, 97);
			this->pictureBoxSelectedCardLeft->TabIndex = 22;
			this->pictureBoxSelectedCardLeft->TabStop = false;
			this->pictureBoxSelectedCardLeft->Visible = false;
			// 
			// pictureBoxSelectedCardRight
			// 
			this->pictureBoxSelectedCardRight->Location = System::Drawing::Point(900, 297);
			this->pictureBoxSelectedCardRight->Name = L"pictureBoxSelectedCardRight";
			this->pictureBoxSelectedCardRight->Size = System::Drawing::Size(73, 97);
			this->pictureBoxSelectedCardRight->TabIndex = 23;
			this->pictureBoxSelectedCardRight->TabStop = false;
			this->pictureBoxSelectedCardRight->Visible = false;
			// 
			// pictureBoxBJGif
			// 
			this->pictureBoxBJGif->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBoxBJGif.Image")));
			this->pictureBoxBJGif->Location = System::Drawing::Point(36, 39);
			this->pictureBoxBJGif->Name = L"pictureBoxBJGif";
			this->pictureBoxBJGif->Size = System::Drawing::Size(320, 180);
			this->pictureBoxBJGif->TabIndex = 24;
			this->pictureBoxBJGif->TabStop = false;
			// 
			// buttonElapsedTime
			// 
			this->buttonElapsedTime->FlatAppearance->BorderColor = System::Drawing::Color::YellowGreen;
			this->buttonElapsedTime->FlatAppearance->BorderSize = 4;
			this->buttonElapsedTime->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Yellow;
			this->buttonElapsedTime->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->buttonElapsedTime->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonElapsedTime->Location = System::Drawing::Point(1051, 135);
			this->buttonElapsedTime->Name = L"buttonElapsedTime";
			this->buttonElapsedTime->Size = System::Drawing::Size(138, 38);
			this->buttonElapsedTime->TabIndex = 25;
			this->buttonElapsedTime->Text = L"Show Elapsed Time";
			this->buttonElapsedTime->UseVisualStyleBackColor = true;
			this->buttonElapsedTime->Click += gcnew System::EventHandler(this, &Form1::buttonElapsedTime_Click);
			// 
			// labelElapsedTime
			// 
			this->labelElapsedTime->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->labelElapsedTime->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelElapsedTime->Location = System::Drawing::Point(957, 176);
			this->labelElapsedTime->Name = L"labelElapsedTime";
			this->labelElapsedTime->Size = System::Drawing::Size(295, 63);
			this->labelElapsedTime->TabIndex = 26;
			this->labelElapsedTime->Text = L"0 seconds elapsed";
			this->labelElapsedTime->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->labelElapsedTime->Visible = false;
			// 
			// timerElapsedTime
			// 
			this->timerElapsedTime->Interval = 1000;
			this->timerElapsedTime->Tick += gcnew System::EventHandler(this, &Form1::timerElapsedTime_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1264, 562);
			this->Controls->Add(this->labelElapsedTime);
			this->Controls->Add(this->buttonElapsedTime);
			this->Controls->Add(this->pictureBoxBJGif);
			this->Controls->Add(this->pictureBoxSelectedCardRight);
			this->Controls->Add(this->pictureBoxSelectedCardLeft);
			this->Controls->Add(this->labelObservation);
			this->Controls->Add(this->labelSumValue);
			this->Controls->Add(this->labelSumName);
			this->Controls->Add(this->labelHorizontalRule);
			this->Controls->Add(this->labelSecondCardValue);
			this->Controls->Add(this->labelFirstCardValue);
			this->Controls->Add(this->labelSecondCardName);
			this->Controls->Add(this->labelFirstCardName);
			this->Controls->Add(this->labelSecondCard);
			this->Controls->Add(this->labelFirstCard);
			this->Controls->Add(this->pictureBoxAceR);
			this->Controls->Add(this->pictureBoxJackR);
			this->Controls->Add(this->pictureBox5R);
			this->Controls->Add(this->pictureBoxAceL);
			this->Controls->Add(this->pictureBoxJackL);
			this->Controls->Add(this->pictureBoxFiveL);
			this->Controls->Add(this->labelInstructions);
			this->Controls->Add(this->buttonPlayOn);
			this->Controls->Add(this->buttonExit);
			this->Controls->Add(this->buttonDateTime);
			this->Controls->Add(this->labelDateTime);
			this->Controls->Add(this->labelWelcome);
			this->Name = L"Form1";
			this->Text = L"Johnny\'s Black Jack Preliminaries";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxFiveL))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxJackL))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxAceL))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxAceR))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxJackR))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5R))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxSelectedCardLeft))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxSelectedCardRight))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxBJGif))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	///////////////////////////////////////////////////////
	//				GLOBAL VARIABLES/OBJECTS
	///////////////////////////////////////////////////////
	static bool firstCardSelected	= false;
	static bool	isUpdating			= false;
	static bool leftSide			= 0;
	static bool rightSide			= 0;
	static int  counter				= 0;
	static int	countBJ				= 0;
	static int	countBusted			= 0;
	static int	countGreaterThan	= 0;
	static int	countLessThan		= 0;
	DateTime	dateTimeStart;
	///////////////////////////////////////////////////////

/**************************************************************
***************************************************************
***                                                			***
***   START EVENT-DRIVEN FUNCTION DECLARATIONS/DEFINITIONS  ***
***                                                			***
***************************************************************
**************************************************************/

/**************************************************************
***                                                			***
***    buttonDateTime_Click									***
***                                                			***
***		Calls displayDateTime function.						***
***                                                			***
**************************************************************/

private: System::Void buttonDateTime_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 displayDateTime();
		 }

/**************************************************************
***                                                			***
***    buttonElapsedTime_Click								***
***                                                			***
***		Toggles timerElapsedTime to show the elapsed time,	***
***		updates the label text to "Show|Hide Elapsed Time"	***
***                                                			***
**************************************************************/

private: System::Void buttonElapsedTime_Click(System::Object^  sender, System::EventArgs^  e) 
			 { 
				 if (isUpdating == false)
				 {
					 buttonElapsedTime->Text = "Hide Elapsed Time";
					 timerElapsedTime->Enabled = true;
					 labelElapsedTime->Visible = true;
				 }

				 else
				 {
					 buttonElapsedTime->Text = "Show Elapsed Time";
					 timerElapsedTime->Enabled = false;
					 labelElapsedTime->Visible = false;
				 }

				 isUpdating = !isUpdating;
			 }

/**************************************************************
***                                                			***
***    buttonExit_Click										***
***                                                			***
***		Calls the farewell function.						***
***                                                			***
**************************************************************/

private: System::Void buttonExit_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 farewell();
		 }

/**************************************************************
***                                                			***
***    pictureBoxAceL_Click									***
***                                                			***
***		Calls selectCard function the name of card, card	***
***		value, card suit, and which side the card is on.	***
***		Checks to see if you already selected a card from	***
***		the left side already. If so, lets selectCard		***
***		function take over and handle the error handling.	***
***                                                			***
**************************************************************/

private: System::Void pictureBoxAceL_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 ///////////////////////////////////////////////////////
			 //				LOCAL VARIABLES/OBJECTS
			 ///////////////////////////////////////////////////////
			 Windows::Forms::DialogResult clickedAce;
			 ///////////////////////////////////////////////////////

			 if (leftSide == 0)		// Make sure we haven't previously selected card from left side
			 {
				 clickedAce = MessageBox::Show("Would you like to make this Ace hard?\n\n"
											   "Click YES to make this Ace count as 11.\n\n"
											   "Otherwise, it will count as 1.", 
											   "Select value for Ace",
											   MessageBoxButtons::YesNo, MessageBoxIcon::Question);

				 if (clickedAce == Windows::Forms::DialogResult::Yes)
					 selectCard("Ace", 11, "s", "left");

				 else
					 selectCard("Ace", 1, "s", "left");
			 }

			 else	// Let selectCard() handle the error control
				 selectCard("Ace", 999, "s", "left");
		 }

/**************************************************************
***                                                			***
***    pictureBoxFiveL_Click								***
***                                                			***
***		Calls selectCard function the name of card, card	***
***		value, card suit, and which side the card is on.	***
***                                                			***
**************************************************************/

private: System::Void pictureBoxFiveL_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 selectCard("Five", 5, "d", "left");
		 }

/**************************************************************
***                                                			***
***    pictureBoxJackL_Click								***
***                                                			***
***		Calls selectCard function the name of card, card	***
***		value, card suit, and which side the card is on.	***
***                                                			***
**************************************************************/

private: System::Void pictureBoxJackL_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 selectCard("Jack", 10, "c", "left");
		 }

/**************************************************************
***                                                			***
***    pictureBoxAceR_Click									***
***                                                			***
***		Calls selectCard function the name of card, card	***
***		value, card suit, and which side the card is on.	***
***		Checks to see if you already selected a card from	***
***		the right side already. If so, lets selectCard		***
***		function take over and handle the error handling.	***
***                                                			***
**************************************************************/

private: System::Void pictureBoxAceR_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 ///////////////////////////////////////////////////////
			 //				LOCAL VARIABLES/OBJECTS
			 ///////////////////////////////////////////////////////
			 Windows::Forms::DialogResult clickedAce;
			 ///////////////////////////////////////////////////////

			 if (rightSide == 0)	// Make sure we haven't previously selected card from right side
			 {
				 clickedAce = MessageBox::Show("Would you like to make this Ace hard?\n\n"
											   "Click YES to make this Ace count as 11.\n\n"
											   "Otherwise, it will count as 1.", 
											   "Select value for Ace",
											   MessageBoxButtons::YesNo, MessageBoxIcon::Question);

				 if (clickedAce == Windows::Forms::DialogResult::Yes)
					 selectCard("Ace", 11, "s", "right");

				 else
					 selectCard("Ace", 1, "s", "right");
			 }

			 else	// Let selectCard() handle the error control
				 selectCard("Ace", 999, "s", "right");
		 }

/**************************************************************
***                                                			***
***    pictureBox5R_Click									***
***                                                			***
***		Calls selectCard function the name of card, card	***
***		value, card suit, and which side the card is on.	***
***                                                			***
**************************************************************/

private: System::Void pictureBox5R_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 selectCard("Five", 5, "d", "right");
		 }

/**************************************************************
***                                                			***
***    pictureBoxJackR_Click								***
***                                                			***
***		Calls selectCard function the name of card, card	***
***		value, card suit, and which side the card is on.	***
***                                                			***
**************************************************************/

private: System::Void pictureBoxJackR_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 selectCard("Jack", 10, "c", "right");
		 }

/**************************************************************
***                                                			***
***    buttonPlayOn_Click									***
***                                                			***
***		Hides picture boxes for selected cards, label sum	***
***		values, and observation. Resets text in labels for	***
***		card name and value. Sets leftSide and rightSide	***
***		variables to 0.  Now we're good for another game.	***
***                                                			***
**************************************************************/

private: System::Void buttonPlayOn_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 // Reset everything back to starting values
			 pictureBoxSelectedCardLeft->Visible = false;
			 pictureBoxSelectedCardRight->Visible = false;
			 labelObservation->Visible = false;
			 labelHorizontalRule->Visible = false;
			 labelSumName->Visible = false;
			 labelSumValue->Visible = false;
			 labelFirstCardName->Text = "1st Card Name";
			 labelFirstCardValue->Text = ". . .";
			 labelSecondCardName->Text = "2nd Card Name";
			 labelSecondCardValue->Text = ". . .";
			 firstCardSelected = false;
			 leftSide = 0;
			 rightSide = 0;
		 }

/**************************************************************
***                                                			***
***    timerElapsedTime_Tick								***
***                                                			***
***		Takes the current time and subtracts from the time	***
***		when the program loaded. Displays this time in		***
***		seconds in a labelElapsedTime.						***
***                                                			***
**************************************************************/

private: System::Void timerElapsedTime_Tick(System::Object^  sender, System::EventArgs^  e) 
		 {
			 ///////////////////////////////////////////////////////
			 //		LOCAL VARIABLES/OBJECTS
			 ///////////////////////////////////////////////////////
			 DateTime	dateTimeNow	= DateTime::Now;
			 TimeSpan	timeSpanDifference;
			 /////////////////////////////////////////////////////// 

			 timeSpanDifference = dateTimeNow.Subtract( dateTimeStart );
			 labelElapsedTime->Text = timeSpanDifference.Minutes.ToString() + " min "
									+ timeSpanDifference.Seconds.ToString() + " seconds elapsed";
		 }

/**************************************************************
***************************************************************
***                                                			***
***   END EVENT-DRIVEN FUNCTION DECLARATIONS/DEFINITIONS    ***
***                                                			***
***************************************************************
**************************************************************/

/**************************************************************
***************************************************************
***                                                			***
***			  START NON EVENT-DRIVEN FUNCTIONS				***
***                                                			***
***************************************************************
**************************************************************/

/**************************************************************
***                                                			***
***    displayDateTime										***
***                                                			***
***		Shows date and time in short form in a label.		***
***                                                			***
**************************************************************/

void displayDateTime()
{
	///////////////////////////////////////////////////////
	//				LOCAL VARIABLES/OBJECTS
	///////////////////////////////////////////////////////
	DateTime dateTimeNow = DateTime::Now;
	///////////////////////////////////////////////////////

	labelDateTime->Text = dateTimeNow.ToShortDateString()
						+ "\n\t"
						+ dateTimeNow.ToShortTimeString();		
}

/**************************************************************
***                                                			***
***    farewell												***
***                                                			***
***		Plays music from the game Portal. Bids player		***
***		farewell and shows stats by use of the counters.	***
***		Displays message ID info and stars in message boxes	***
***                                                			***
**************************************************************/

void farewell()
{
	/////////////////////////////////////////////////////////////
	//		DECLARE LOCAL VARIABLES 
	/////////////////////////////////////////////////////////////
	System::Media::SoundPlayer soundPlayer ( "wav/portal.wav");
	/////////////////////////////////////////////////////////////

	soundPlayer.PlayLooping();

	MessageBox::Show("Thanks for playing Johnny's BlackJack Prelims!\n\nYour play stats:\n"
					+ "\nBlackJack:	" + countBJ.ToString()
					+ "\n15<>21:	" + countGreaterThan.ToString()
					+ "\n<16:	" + countLessThan.ToString()
					+ "\nBusted:	" + countBusted.ToString() );
	MessageBox::Show( 
				"*************************************************************************************\n"
				 "**************************************** ID INFO ************************************\n\n"
				 "	Programmer		:	Johnny Brinsko\n"
				 "	Assignment #		:	TA 2.BJ\n"
				 "	Assignment Name		:	GUI BlackJack Preliminaries\n"
				 "	Course # and Title		:	CISC 192  - C++\n"
				 "	Class Meeting Time		:	TTh 9:35 - 12:40\n"
				 "	Instructor			:	Professor Forman\n"
				 "	Hours			:	9\n"
				 "	Difficulty			:	4\n"
				 "	Completion Date		:	10/30/2012\n"
				 "	Project Name		:	JohnnyBJPreliminaries\n\n"
				 "**************************************************************************************\n"
				 "**************************************** CREDITS ************************************\n\n"
				 "	Thanks to Professor Forman and Tim for completing the \n"
				 "			learning triangle together\n\n"
				 "*************************************************************************************\n"
				 "**************************************** MEDIA *************************************\n\n"
				 "Farewell music:\n"
				 "http://www.gamefront.com/files/12899141/Portal_Radio_Loop" 
				 "\n\nJose's cards from class, provided by Professor Forman"
				 "\n\nAnimated gif of blackjack dealing\n"
				 "	(used gifsoup.com to convert video to gif)\n"
				 "http://www.youtube.com/watch?v=V6WQrbauJEQ"
				 );
		MessageBox::Show(
				 "*************************************************************************************\n"
				 "************************************** # OF STARS **********************************\n\n"
				 "8 stars\n\n"
				 "*************************************************************************************\n"
				 "**************************************** STARS *************************************\n\n"
				 "1. Display image of card selected in the appropriate picture box\n"
				 "2. Prevent user from selecting two cards from a single column\n"
				 "3. Click only once in each column\n"
				 "4. When player clicks card, display in message box the card name and value.\n"
				 "5. If the player selects an Ace, give the player a choice of using the Ace as 11 or 1.\n"
				 "6. In the farewell, report how many times the card sums were of each result.\n"
				 "7. Demo before the due date.\n"
				 "8. Display elapsed time.\n"
				 );
	Close();
}

/**************************************************************
***                                                			***
***    observeCards											***
***                                                			***
***		Display results of the sum of the card values in a	***
***		label. Adds one to the appropriate counter.			***
***                                                			***
**************************************************************/

void observeCards(int sumValue)
{
	if (sumValue == 21)
	{
		countBJ++;
		labelObservation->Text = "Winner Winner, Chicken Dinner";
	}

	else if (sumValue > 21)
	{
		countBusted++;
		labelObservation->Text = "B U S T E D !";
	}
	
	else if (sumValue >= 16)
	{
		countLessThan++;
		labelObservation->Text = "You should stay";
	}
	
	else
	{
		countGreaterThan++;
		labelObservation->Text = "You should get hit";
	}
}

/**************************************************************
***                                                			***
***    selectCard											***
***                                                			***
***		Makes you only select from one set of cards.		***
***		Will throw an error in a message box if you try.	***
***		Checks to see if you already selected a card.		***
***		Shows selected card in separate picture box as		***
***		well as name and value in appropriate label.		***
***		After two cards are selected, one from each column,	***
***		adds the value of the selected cards and passes the	***
***		sum to the observeCards function.					***
***                                                			***
**************************************************************/

void selectCard(String^ stringCardName, int intCardValue, String^ stringCardSuit, String^ leftOrRight)
{
	///////////////////////////////////////////////////////
	//				LOCAL VARIABLES/OBJECTS
	///////////////////////////////////////////////////////
	int		sumValue,
			firstCardValue,
			secondCardValue;
	Image^	selectedCardImage;
	///////////////////////////////////////////////////////

	// If selected card is from the left side:
	if (leftOrRight == "left")
	{
		if (leftSide < 1)	// Check to see if this is the first time selecting a card from the left side
		{
			leftSide++;		// This will make sure we don't pick from the left side again
			if ( firstCardSelected == false)
			{
				// Burpback card selection
				MessageBox::Show(String::Concat("Thanks for selecting the ", stringCardName, 
												" with a value of ", intCardValue, "."),
												"Your Selected Card");

				// Show card info in labels
				labelFirstCardName->Text  = stringCardName;
				labelFirstCardValue->Text = intCardValue.ToString();

				// Show selected card in separate picture box
				pictureBoxSelectedCardLeft->Visible = true;
				selectedCardImage = Image::FromFile(L"img/" + stringCardName + stringCardSuit + ".gif");
				pictureBoxSelectedCardLeft->Image = selectedCardImage;

				// Confirm that this card is the first selected
				firstCardSelected         = true;
			}

			else	// We must've already selected the first card
			{
				// Burpback card selection
				MessageBox::Show(String::Concat("Thanks for selecting the ", stringCardName, 
												" with a value of ", intCardValue, "."),
												"Your Selected Card");

				// Show card info in labels
				labelSecondCardName->Text   = stringCardName;
				labelSecondCardValue->Text  = intCardValue.ToString();

				// Show selected card in separate picture box
				pictureBoxSelectedCardLeft->Visible = true;
				selectedCardImage = Image::FromFile(L"img/" + stringCardName + stringCardSuit + ".gif");
				pictureBoxSelectedCardLeft->Image = selectedCardImage;

				// Confirm that this card is the first selected
				firstCardSelected			= false;
			}
		}

		// The catch to see if we picked from BOTH the left AND right collection of cards already
		else if (rightSide >= 1 && leftSide >= 1)
		{
			System::Media::SystemSounds::Hand->Play();
			MessageBox::Show("Press the Play On button to play another game");
		}

		else	// This must not be the first time you clicked on the left side
		{
			System::Media::SystemSounds::Hand->Play();
			MessageBox::Show("Choose a card from the right side!");
		}
	}

	// If selected card is from the right side:
	if (leftOrRight == "right")
	{
		if (rightSide < 1)	// Check to see if this is the first time selecting a card from the right side
		{
			rightSide++;	// This will make sure we don't pick from the right side again

			if ( firstCardSelected == false)
			{
				// Burpback card selection
				MessageBox::Show(String::Concat("Thanks for selecting the ", stringCardName, 
												" with a value of ", intCardValue, "."),
												"Your Selected Card");

				// Show card info in labels
				labelFirstCardName->Text  = stringCardName;
				labelFirstCardValue->Text = intCardValue.ToString();

				// Show selected card in separate picture box
				pictureBoxSelectedCardRight->Visible = true;
				selectedCardImage = Image::FromFile(L"img/" + stringCardName + stringCardSuit + ".gif");
				pictureBoxSelectedCardRight->Image = selectedCardImage;

				// Confirm that this card is the first selected
				firstCardSelected         = true;
			}

			else	// We must've already selected the first card
			{
				// Burpback card selection
				MessageBox::Show(String::Concat("Thanks for selecting the ", stringCardName, 
												" with a value of ", intCardValue, "."),
												"Your Selected Card");

				// Show card info in labels
				labelSecondCardName->Text   = stringCardName;
				labelSecondCardValue->Text  = intCardValue.ToString();

				// Show selected card in separate picture box
				pictureBoxSelectedCardRight->Visible = true;
				selectedCardImage = Image::FromFile(L"img/" + stringCardName + stringCardSuit + ".gif");
				pictureBoxSelectedCardRight->Image = selectedCardImage;

				// Confirm that this card is the first selected
				firstCardSelected			= false;
			}
		}

		// The catch to see if we picked from both the left and right collection of cards already
		else if (rightSide >= 1 && leftSide >= 1)
		{
			System::Media::SystemSounds::Hand->Play();
			MessageBox::Show("Press the Play On button to play another game");
		}
	
		else	// This must not be the first time you clicked on the left side
		{
			System::Media::SystemSounds::Hand->Play();
			MessageBox::Show("Choose a card from the left side!");
		}
	}

	// After two cards are selected, display the sum of both card values
	if (firstCardSelected == false)
	{
		labelHorizontalRule->Visible = true;
		labelSumName->Visible = true;
		labelSumValue->Visible = true;

		// Convert string of the card value to int so we can add it up
		int::TryParse(labelFirstCardValue->Text, firstCardValue);
		int::TryParse(labelSecondCardValue->Text, secondCardValue);
		sumValue = firstCardValue + secondCardValue;
		labelSumValue->Text = sumValue.ToString();

		// Let's see if we've won or not
		observeCards(sumValue);
		labelObservation->Visible = true;
	}

	// Let user know that a bunch of stuff just happened
	SystemSounds::Asterisk->Play();
}

/**************************************************************
***************************************************************
***                                                			***
***			    END NON EVENT-DRIVEN FUNCTIONS				***
***                                                			***
***************************************************************
**************************************************************/

};
}