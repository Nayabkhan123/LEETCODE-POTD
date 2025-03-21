/*
    You have information about n different recipes. You are given a string array recipes and a 2D 
    string array ingredients. The ith recipe has the name recipes[i], and you can create it if you 
    have all the needed ingredients from ingredients[i]. A recipe can also be an ingredient for 
    other recipes, i.e., ingredients[i] may contain a string that is in recipes.

    You are also given a string array supplies containing all the ingredients that you initially 
    have, and you have an infinite supply of all of them.

    Return a list of all the recipes that you can create. You may return the answer in any order.

    Note that two recipes may contain each other in their ingredients.
*/

class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            unordered_map<string,vector<string>> adj;
            unordered_map<string,int> indegree;
    
            unordered_set<string> supply(supplies.begin(),supplies.end());
            for(int i=0;i<recipes.size();++i){
                indegree[recipes[i]] = 0;
                for(string& ingredient: ingredients[i]){
                    if(supply.count(ingredient)==0){
                        adj[ingredient].push_back(recipes[i]);
                        indegree[recipes[i]]++;
                    }
                }
            }
            queue<string> q;
            for(auto& [recipe,indeg]: indegree)
                if(indeg==0)
                    q.push(recipe);
            
            vector<string> res;
            while(!q.empty()){
                string curr_recipe = q.front();
                q.pop();
                res.push_back(curr_recipe);
    
                for(string& next_recipe: adj[curr_recipe]){
                    indegree[next_recipe]--;
                    if(indegree[next_recipe]==0)
                        q.push(next_recipe);
                }
            }
            return res;
        }
    };