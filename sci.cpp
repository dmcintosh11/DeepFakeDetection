#include <iostream>
#include <tuple>
using namespace std;

class Weight
{
  public:
    tuple<int, int> weightAsses(char correct_list[], char compare_list[], int weight_1, int weight_2);
};

tuple<int, int> Weight::weightAsses(char correct_list[], char compare_list[], int weight_1, int weight_2)
{
    for (int i = 0; i < 5; i++) {
        if (compare_list[i] == correct_list[i]) {
            if (weight_1 == 10) {
                weight_1 += 0;
                if (weight_2 == 0) {
                    continue;
                }
                else {
                    weight_2 -= 1;
                }
              }
              else {
                  weight_1 += 1;
                  if (weight_2 == 0) {
                      continue;
                  }
                  else {
                      weight_2 -= 1;
                  }
              }
        }
        else {
          if (weight_1 == 0) {
              weight_1 -= 0;
              if (weight_2 == 10) {
                  continue;
              }
              else {
                  weight_2 += 1;
              }
            }
            else {
                weight_1 -= 1;
                if (weight_2 == 0) {
                    continue;
                }
                else {
                    weight_2 += 1;
                }
            }
        }
      }

        tuple<int, int> tuple(weight_1, weight_2);
        return tuple;

  }


int main()
{
  Weight w;

  int artifact_weight = 5;
  int facial_weight = 5;

  string artifact = "FFFTTTFFFF";
  char artifact_list[artifact.length()];
  int i = 0;
  for (i = 0; i < sizeof(artifact_list); i++) {
        artifact_list[i] = artifact[i];
  }

  string facial = "TTFTTTFFTF";
  char facial_list[facial.length()];
  for (i = 0; i < sizeof(facial_list); i++) {
        facial_list[i] = facial[i];
  }

  string correct = "TTFTTTFTTF";
  char correct_list[correct.length()];
  for (i = 0; i < sizeof(correct_list); i++) {
        correct_list[i] = correct[i];
  }

  tie(artifact_weight, facial_weight) = w.weightAsses(correct_list, artifact_list, artifact_weight, facial_weight);
  tie(facial_weight, artifact_weight) = w.weightAsses(correct_list, facial_list, facial_weight, artifact_weight);

  cout << "Artifact Weight: " << artifact_weight << endl;
  cout << "Facial Weight: " << facial_weight << endl;

  return 0;
}
