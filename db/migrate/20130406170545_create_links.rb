class CreateLinks < ActiveRecord::Migration
  def change
    create_table :links do |t|
      t.string :hash
      t.datetime :accessed_at

      t.timestamps
    end
  end
end
