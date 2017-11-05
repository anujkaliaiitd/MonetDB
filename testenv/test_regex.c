#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "test_regex.h"

int main(int argc, char const *argv[]){
  const char* rule = "a+";
  const char* source = "a";

  printf("rule: %s\n", rule);
  printf("source: %s\n", source);

  struct reg_env* env = reg_open_env();

  struct reg_pattern* pattern = reg_new_pattern(env, rule);
  int success = reg_match(pattern, source, strlen(source));
  printf("-------------- reslut -----------\n success: %d\n", success);
  reg_close_env(env);
  return 0;
}
