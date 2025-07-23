#include <cliext/list>
#include <cliext/vector>
#include <windows.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Diagnostics;
using namespace System::Drawing;
using namespace System::Collections::Generic;

public ref class SortifyForm : public Form {
public:
    SortifyForm() {
        InitializeComponent();
    }

private:
    TextBox^ inputBox;
    Button^ compareButton;
    ListBox^ resultBubble;
    ListBox^ resultMerge;
    Label^ stepsBubble;
    Label^ stepsMerge;
    Label^ timeBubble;
    Label^ timeMerge;

    void InitializeComponent() {
        this->Text = "Sorting Algorithm Simulator & Comparator";
        this->Size = Drawing::Size(1000, 700);
        this->StartPosition = FormStartPosition::CenterScreen;
        this->Font = gcnew Drawing::Font("Segoe UI", 10);

        Label^ lblInput = gcnew Label();
        lblInput->Text = "Enter numbers (comma-separated):";
        lblInput->Location = Point(30, 20);
        lblInput->Size = Drawing::Size(300, 20);

        inputBox = gcnew TextBox();
        inputBox->Location = Point(30, 50);
        inputBox->Width = 700;

        compareButton = gcnew Button();
        compareButton->Text = "Compare Algorithms";
        compareButton->Location = Point(750, 47);
        compareButton->Size = Drawing::Size(180, 30);
        compareButton->Click += gcnew EventHandler(this, &SortifyForm::RunComparison);

        Label^ lblBubble = gcnew Label();
        lblBubble->Text = "Bubble Sort Result";
        lblBubble->Location = Point(30, 100);
        lblBubble->Font = gcnew Drawing::Font("Segoe UI", 10, FontStyle::Bold);

        resultBubble = gcnew ListBox();
        resultBubble->Location = Point(30, 130);
        resultBubble->Size = Drawing::Size(400, 300);

        stepsBubble = gcnew Label(); stepsBubble->Location = Point(30, 450); stepsBubble->Size = Drawing::Size(400, 20);
        timeBubble = gcnew Label(); timeBubble->Location = Point(30, 480); timeBubble->Size = Drawing::Size(400, 20);

        Label^ lblMerge = gcnew Label();
        lblMerge->Text = "Merge Sort Result";
        lblMerge->Location = Point(500, 100);
        lblMerge->Font = gcnew Drawing::Font("Segoe UI", 10, FontStyle::Bold);

        resultMerge = gcnew ListBox();
        resultMerge->Location = Point(500, 130);
        resultMerge->Size = Drawing::Size(400, 300);

        stepsMerge = gcnew Label(); stepsMerge->Location = Point(500, 450); stepsMerge->Size = Drawing::Size(400, 20);
        timeMerge = gcnew Label(); timeMerge->Location = Point(500, 480); timeMerge->Size = Drawing::Size(400, 20);

        this->Controls->AddRange(gcnew array<Control^> {
            lblInput, inputBox, compareButton,
                lblBubble, resultBubble, stepsBubble, timeBubble,
                lblMerge, resultMerge, stepsMerge, timeMerge
        });
    }

    Tuple<List<int>^, int>^ BubbleSort(List<int>^ data) {
        int steps = 0;
        for (int i = 0; i < data->Count - 1; i++) {
            for (int j = 0; j < data->Count - i - 1; j++) {
                steps++;
                if (data[j] > data[j + 1]) {
                    int temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
        return Tuple::Create(data, steps);
    }

    Tuple<List<int>^, int>^ MergeSort(List<int>^ data) {
        int steps = 0;
        List<int>^ sorted = MergeSortRecursive(data, steps);
        return Tuple::Create(sorted, steps);
    }

    List<int>^ MergeSortRecursive(List<int>^ data, int% steps) {
        if (data->Count <= 1)
            return data;

        int mid = data->Count / 2;
        List<int>^ left = data->GetRange(0, mid);
        List<int>^ right = data->GetRange(mid, data->Count - mid);

        left = MergeSortRecursive(left, steps);
        right = MergeSortRecursive(right, steps);

        return Merge(left, right, steps);
    }

    List<int>^ Merge(List<int>^ left, List<int>^ right, int% steps) {
        List<int>^ result = gcnew List<int>();
        int i = 0, j = 0;

        while (i < left->Count && j < right->Count) {
            steps++;
            if (left[i] <= right[j]) {
                result->Add(left[i++]);
            }
            else {
                result->Add(right[j++]);
            }
        }

        while (i < left->Count) result->Add(left[i++]);
        while (j < right->Count) result->Add(right[j++]);

        return result;
    }

    void RunComparison(Object^ sender, EventArgs^ e) {
        array<String^>^ parts = inputBox->Text->Split(',');
        List<int>^ originalData = gcnew List<int>();

        for each (String ^ part in parts) {
            int value;
            if (Int32::TryParse(part->Trim(), value)) {
                originalData->Add(value);
            }
        }

        if (originalData->Count == 0) {
            MessageBox::Show("Please enter a valid list of integers separated by commas.", "Input Error");
            return;
        }

        List<int>^ dataForBubble = gcnew List<int>(originalData);
        List<int>^ dataForMerge = gcnew List<int>(originalData);

        Stopwatch^ swBubble = Stopwatch::StartNew();
        auto bubbleResult = BubbleSort(dataForBubble);
        swBubble->Stop();

        Stopwatch^ swMerge = Stopwatch::StartNew();
        auto mergeResult = MergeSort(dataForMerge);
        swMerge->Stop();

        resultBubble->Items->Clear();
        for each (int val in bubbleResult->Item1)
            resultBubble->Items->Add(val);
        stepsBubble->Text = "Steps (Comparisons): " + bubbleResult->Item2;
        timeBubble->Text = "Execution Time: " + swBubble->Elapsed.TotalMilliseconds.ToString("F3") + " ms";

        resultMerge->Items->Clear();
        for each (int val in mergeResult->Item1)
            resultMerge->Items->Add(val);
        stepsMerge->Text = "Steps (Merges/Comparisons): " + mergeResult->Item2;
        timeMerge->Text = "Execution Time: " + swMerge->Elapsed.TotalMilliseconds.ToString("F3") + " ms";
    }
};

[STAThread]
int main(array<System::String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew SortifyForm());
    return 0;
}
